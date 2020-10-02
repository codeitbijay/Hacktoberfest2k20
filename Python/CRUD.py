# CRUD Script in bahasa (translated)

done = []

def selesai(): #done
    if (len(done) <= 0):
        print ('NOT FOUND')
    else:
        for i in range(len(done)):
            print(i,done[i])

def masuk(): #input
    baru = input('Masukkan yang sudah selesai : ') #input anything you have done
    done.append(baru)


def ubah(): #change
    selesai()
    i = int(input('Masukkan id : ')) #input id u wanna change
    if (len(done) < i):
        print('INVALID')
    else:
        sls = input('apa yg sudah dilakukan : ') #what have u done
        done[i] = sls
        

def hapus(): #delete
    selesai()
    i = int(input('Masukkan ID : ')) #inpu id u wanna delete
    if (len(done) < i):
        print('INVALID')
    else:
        done.remove(done[i])

def menu():
    print('\n')
    print('='*15,'MENU','='*15)
    print('[1] LIST')
    print('[2] ADD')
    print('[3] CHANGE')
    print('[4] DELETE')
    print('[5] EXIT')

    menu = int(input('Pilih menu : ')) #choose menu
    print('\n')

    if(menu == 1):
        selesai()
    elif(menu==2):
        masuk()
    elif(menu==3):
        ubah()
    elif(menu==4):
        hapus()
    elif(menu==5):
        exit()
    else:
        print('TIDAK TERSEDIA')

if __name__ == "__main__":
    while(True):
        menu()