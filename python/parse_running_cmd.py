#!/usr/bin/env python

from subprocess import Popen, PIPE, STDOUT
from threading  import Thread
import time
try:
    from Queue import Queue, Empty
except ImportError:
    from queue import Queue, Empty  # python 3.x


ROT_ANIM = ('-', '\\', '|', '/',)

def enqueue_output(out, queue):
    for line in iter(out.readline, b''):
        queue.put(line)
    out.close()


def main():
    " Go, go, go"
    # Launch process
    the_program = "./output_gen.sh"
    p = Popen(
            [the_program,], # Args as list
            stdout=PIPE, # Send both stdout and stderr back to us
            stderr=STDOUT, # In fact, send them both to stdout
            shell=True,
    )
    q = Queue()
    t = Thread(target=enqueue_output, args=(p.stdout, q))
    t.daemon = True # thread dies with the program
    t.start()

    i = 0
    output_line = ""
    while p.poll() is None: # When p terminates, p.poll() sets and returns a return value
        try:  line = q.get(timeout=.1) # or q.get_nowait()
        except Empty:
            pass # There's no output yet
        else: # got line
            status = chr(8) + 'Progress: {0} {1}'.format(
                        ROT_ANIM[i],
                        line.strip()[-2:] # This would actually be a regex or something
            )
            status += chr(8)*(len(status)+1)
            print status,
            i = (i + 1) % len(ROT_ANIM)

if __name__ == "__main__":
    main()
