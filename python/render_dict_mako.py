#!/usr/bin/env python
# TAGS: templates, python
from mako.template import Template

TPL = """
Name:    ${name}
Age:     ${age}
Numbers: ${numbers}
Check:   ${check}
% if name == 'John':
    It's John!
% elif name == 'Mary':
% else:
    It's someone else!
% endif
"""

def print_rendered_output(**kwargs):
    """docstring for print_rendered_output"""
    my_tpl = Template(TPL)
    kwargs['check'] = True
    print my_tpl.render(**kwargs)


if __name__ == "__main__":
    d = {'name': 'Jack', 'age': 23, 'numbers': (1, 2, 5)}
    print_rendered_output(**d)
