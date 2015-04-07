import shared_mod
import mod1


print "mod1: bar == ", shared_mod.f.bar
shared_mod.f.bar = 7
print "mod1: bar == ", shared_mod.f.bar
