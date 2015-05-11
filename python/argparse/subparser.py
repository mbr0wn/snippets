#!/usr/bin/env python

import argparse

def main():
    """ Go ,go, go! """
    # Create parser:
    parser = argparse.ArgumentParser(description="Subparser demo")
    parser.add_argument('--global')
    subparsers = parser.add_subparsers(help='sub-command help')

    # First sub-parser:
    parser_a = subparsers.add_parser('a', help='a help')
    parser_a.add_argument('--local-a', type=int, help='local-a help')

    # Second sub-parser:
    parser_b = subparsers.add_parser('b', help='b help')
    parser_b.add_argument('--local-b', type=int, help='local-b help')

    parser.add_argument('--last')

    parser.parse_args()
    # Try -h or 'a -h'

if __name__ == "__main__":
    main()

