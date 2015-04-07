import shared_mod

print "mod1: bar == ", shared_mod.f.bar
shared_mod.f.bar = 6
print "mod1: bar == ", shared_mod.f.bar
