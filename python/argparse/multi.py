#!/usr/bin/env python

import argparse

def main():
    """ Go ,go, go! """
    # Create parser:
    parser = argparse.ArgumentParser(description="argparse1", add_help=False)
    parser.add_argument(
            '--foo',
            help="foo bar",
            default="bar",
    )
    print "Parser 1:"
    args = parser.parse_known_args()[0]
    print args.foo

    parser2 = argparse.ArgumentParser(description="argparse2", add_help=True)
    parser2.add_argument(
            '--foo',
            help="foo lol",
            default='bar'
    )
    print "Parser 2:"
    args2 = parser2.parse_args()
    print args2.foo

if __name__ == "__main__":
    main()

