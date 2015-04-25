#!/usr/bin/env python

import argparse


def main():
    """ Go ,go, go! """
    # Create parser:
    parser = argparse.ArgumentParser(
            description="Demo basic argparse", # Displayed before a help screen
            epilog="That's it.", # Displayed after a help screen
    )
    # Add options:
    # Simple option (gets stored as string):
    parser.add_argument(
            '-f',
            '--foo',
            help="foo bar",
            default="bar",
    )
    # Simple option w/ type:
    parser.add_argument(
            '--int',
            type=int, # a callback that takes an str
            default=5,
    )
    # Append to list:
    parser.add_argument(
            '--config',
            help="add config option",
            action='append'
    )
    # Count (allows -vvv, -v -v -v, -vv --verbose, etc.)
    parser.add_argument(
            '-v',
            '--verbose',
            help="verbosity level",
            action="count",
    )
    # Positionals:
    parser.add_argument(
            'numbers',
            help="list number",
            nargs='*', # Means we collect them all, or none
    )

    args = parser.parse_args()
    print args.foo
    print args.config
    print args.verbose
    print args.numbers

if __name__ == "__main__":
    main()

