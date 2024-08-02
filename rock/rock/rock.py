import random  #uvodi se modul random da bi mogli da izvucemo odredjene 

random_choice=random.randint(0,2)   #igra je papir, kamen, makaze, da bi racunar mogao da izabere jedno od tih generisemo
                                     # njegov izbor         
winner=' ' #winner je za sada prazan

if random_choice==0: #generisana je neka random vrednost, sada to pretvorimo u reci papir, kamen ili makaze
    computer_choice='kamen'
elif random_choice==1:
       computer_choice='papir'
else:
    computer_choice='makaze'

user_choice=' '  #pitaj korisnika da izabere preko funkcije input

while (user_choice != 'kamen' and 
    user_choice !='makaze' and 
    user_choice !='papir'):
    user_choice=input('kamen,papir ili makaze? ')


if user_choice==computer_choice:
    winner='Nereseno' #racunar i korisnikov izbor se poklapaju, znaci nereseno je
elif computer_choice=='kamen' and user_choice=='makaze':  #ovde smo naprivili situacije u kojima samo racunar pobedjuje
    winner='Racunar'
elif computer_choice=='makaze' and user_choice=='papir':  #poredimo izbor racunara i izbor korisnika
    winner='Racunar'
elif computer_choice=='papir'  and user_choice=='kamen':
    winner='Racunar'
else:                             #u svim situacija gde racunar nije pobednik, jedino slucaj je da je korisnik pobedio
    winner='Korisnik'             #ako je nereseno vec smo na pocetku koda definisali

if winner=='Nereseno':
    print('Oboje biramo',computer_choice +', igraj opet.')  #ispisi ko je pobednik
else:
    print(winner, 'pobedjuje, birao sam', computer_choice+'.')
if winner=='Korisnik':
    print('Bravo doktore')
elif winner=='Racunar':
    print('Majmune')
