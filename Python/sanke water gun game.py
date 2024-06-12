import random
s = ['snake', 'water', 'gun']
cw = 0
uw = 0
tg = 0
terms = int(1)
while terms <= 10:
    uc = int(input('Enter 0(snake),1(water) or 2(gun):'))
    cc = random.choice(s)
    if uc == 0 and cc == 'water':
        uw += 1
        print(f"\nyour choice:{s[uc]}\ncomputer choice:{cc}\nyour score:{uw}\ncomputer score:{cw}\nremaining terms:{10- terms}\n")
    elif uc == 1 and cc == 'gun':
        uw += 1
        print(f"\nyour choice:{s[uc]}\ncomputer choice:{cc}\nyour score:{uw}\ncomputer score:{cw}\nremaining terms:{10- terms}\n")
    elif uc == 2 and cc == 'snake':
        uw += 1
        print(f"\nyour choice:{s[uc]}\ncomputer choice:{cc}\nyour score:{uw}\ncomputer score:{cw}\nremaining terms:{10- terms}\n")
    elif s[uc]==cc:
        tg += 1
        print("\ntie\n")
    else:
        cw += 1
        print(f"\nyour choice:{s[uc]}\ncomputer choice:{cc}\nyour score:{uw}\ncomputer score:{cw}\nremaining terms:{10 - terms}\n")
    terms += 1
if uw > cw:
    print(f"\n\nResult:-\n\nyou won!\nyour score:{uw}\ncomputer score:{cw}\nNo. of ties:{tg}\n")
if cw > uw:
    print(f"\n\nResult:-\n\nyou lose\ncomputer won!\nyour score:{uw}\ncomputer score:{cw}\nNo. of ties:{tg}\n")
if uw == cw:
    print(f"\n\nResult:-\n\ntie game!\nyour score:{uw}\ncomputer score:{cw}\nNo. of ties:{tg}\n")