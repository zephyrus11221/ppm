print('hi')

f = open('pic.ppm','w')
f.truncate()
f.write('P3 500 500 255\n')

r=0
g=0
b=255

for y in range(0,500):
    for x in range(0,500):
        f.write(''+str(r+(y*y-x*y+x)%255)+' '+str(g+(x*y+y)%255)+' '+str(b+(x*(x-y)-y)%255)+'\n')

f.close()
