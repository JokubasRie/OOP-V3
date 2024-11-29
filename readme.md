# 2 užduotis

## V1.1
### Pokytis
Pasirinkta greičiausiai veikianti strategija ( 3 strategija su list konteineriu) bei joje pareita nuo struktūros prie class.

## Laikai
### 1000000:
| VEIKSMAS                              | struct - list              | class - list              |
| ------------------------------------- | -------------------------- | ------------------------- |
| Nuskaitymo iš failo laikas (s)        | 4,76952                    | 5,80052                   |
| Rūšiavimo laikas  (s)                 | 0,826462                   | 0,860157                  |
| Dalijimo į dvi kategorijas laikas (s) | 0.663374                   | 0,774395                  |
| Vargšiukų išvedimo į failą laikas (s) | 0.423652                   | 0,459611                  |
| Kietiakų išvedimo į failą laikas (s)  | 0.690351                   | 0,709529                  |

### 10000000:
| VEIKSMAS                              | struct - list              | class - list              |
| ------------------------------------- | -------------------------- | ------------------------- |
| Nuskaitymo iš failo laikas (s)        | 57,5271                    | 71,515                    |
| Rūšiavimo laikas (s)                  | 14,0141                    | 14,4516                   |
| Dalijimo į dvi kategorijas laikas (s) | 20,7895                    | 15,8954                   |
| Vargšiukų išvedimo į failą laikas (s) | 6,93211                    | 6,6906                    |
| Kietiakų išvedimo į failą laikas (s)  | 9,10787                    | 8,12001                   |

### Išvada
Naudojant tiek class, tiek struct, testiniai laikai skyrėsi nežymiai. Su struct buvo truputį greitesni, taip yra dėl to, kad struktūra yra kiek paprastesnis tipas už klasę.

## Struct ir Klasės versija ištirta su optimizavimo "flagais" (yra lentelė: greitis, exe failo dydis)
### 1000000 su class:
| VEIKSMAS                              | O1 - class | O2 - class | O3 - class | O1 - struct | O2 - struct | O3 - struct |
| ------------------------------------- | -----------| ---------- |----| ---------------|-----|-----|
| Nuskaitymo iš failo laikas (s)        | 3.1338     | 3.8297     | 2.82809 | 2.36331 | 1.77297 | 1.76746 |
| Rūšiavimo laikas  (s)                 | 0.796284   | 0.872654   | 0.824136 | 0.86637 | 0.45788 | 0.450768 |
| Dalijimo į dvi kategorijas laikas (s) | 0.818503   | 0.892311   | 0.822055 | 0.730197 | 0.460517 | 0.454594 |
| Vargšiukų išvedimo į failą laikas (s) | 0.497318   | 0.570769   | 0.50281  | 0.511734 | 0.323299 | 0.334027 |
| Kietiakų išvedimo į failą laikas (s)  | 0.718272   | 0.790122   | 0.754015 | 0.788232 | 0.498377 | 0.544115 |

##  10000000 su class:

| VEIKSMAS                              | O1 - class | O2 - class | O3 - class | O1 - struct | O2 - struct | O3 - struct |
| ------------------------------------- | -----------| ---------- |----| ---------------|-----|-----|
| Nuskaitymo iš failo laikas (s)        | 33.7273    | 40.997 | 30.7714 | 31.0107 | 22.056 |
| Rūšiavimo laikas  (s)                 | 24.3186    | 15.8573 | 15.9412 | 16.1357 | 11.3657 |
| Dalijimo į dvi kategorijas laikas (s) | 92.5839    | 13.139 | 22.0915 | 9.8583 | 15.8276 |
| Vargšiukų išvedimo į failą laikas (s) | 9.15377    | 6.72808 | 6.04138 | 7.29364 | 4.08662 |
| Kietiakų išvedimo į failą laikas (s)  | 8.8668     | 8.38991 | 6.36346 | 8.90526 | 6.00892 | 

### exe failo dydžiai baitais:
 Optimizavimo lygis     | Class   | Struct  |
|--------------|--------------|--------------|
| O1 | 201 309  |   |
| O2 | 203 446 |   |
| O3 | 206 178 |   |

# 1 užduotis
## V.pradinė
1. Sukurta struktūra, kuri aprašo studento duomenis.
2. Sukurtos funkcijos leidžiančios vartotojui įvesti duomenis ranka, pasirinkti namų darbų įvedimo būdą.
3. Sukurtos funkcijos, kurios vartotojui pateikus duomenis pasirinktinai apskaičiuoja vidurkį, medianą arba abi reikšmės.

## V0.1
1. Pridėta duomenų nuskaitymo iš failo galimybė.
2. Pridėta galimybė pasirinkti vieną iš keturių pateiktų failų, kurį norima nuskaityti.
3. Pridėtas studentų rūšiavimas pagal vardą.


## Programos veikimo paaiškinimas 1
1. Paleidus programą vartotojas turi galimybę pasirinkti, ar nori pats įvesti duomenis ar nori juos nuskaityti iš failo ( turi įvesti 1, jei nori nuskaityti duomenis iš failo arba 0, jei nori juos įvesti pats).
   - Jeigu įvedamas sąlygoje nenurodytas variantas, programa išmeta klaidą bei pasiūlo bandyti iš naujo.
   - Pasirinkus, jog duomenis norite nuskaityti iš failo, vartotojui pasiūlomi 4 skirtingi failų variantai bei leidžiama pasirinkti norimą. Jei įvedamas ne atitinkamą failą žymintis simbolis (šiuo atveju skaičius nuo 1 iki 4), tai automatiškai skaičiavimams parenkamas kursiokai.txt failas. Toliau vartotojui leidžiama pasirinkti, ka nori apskaičiuoti (1 - vidurkį, 2 - medianą, 0 - abu). Vėlgi, jei įvedamas sąlygoje nenurodytas simbolis išspausdinama klaida, jog pasirinkimas buvo neteisingas. Teisingu atveju - išspausdinama duomenų lentelė. 
   - Vartotojui pasirinkus rankinio įvedimo atvejį, jo paklausiama, kelių studentų duomenis norės pateikti (galimas pasirinkimas - bet koks sveikasis skaičius). Pasirinkus norimą studentų skaičių, paprašoma pateikti jų visų duomenis (vardą, pavardę, namų darbų pažymius ir egzamino pažymį). Prieš vedant namų darbų pažymius vartotojo paklausiama, ar jis juos ir egzamino pažymį nori suvesti pats ar nori, kad programa pažymius sugeneruotų automatiškai. Jei pasirenka, kad duomenys būtų sugeneruoti automatiškai, tai paklausiama, kiek namų darbų pažymių sugeneruoti. Na, o jei pasirenka, jog duomenis nori įvesti pats, tai paprašoma suvesti visus pažymius bei egzamino rezultatą. Programa supranta, kad suvesti visi pažymiai, kai naudotojas įveda -1. Svarbu, kad namų darbų ir egzamino pažymys turi būti įvedamas dešimtbalėje skalėje. Kai pažymiai būna suvesti arba sugeneruoti automatiškai, tai tada paklausiamas paskutinis klausimas: ,,Ką norite apskaičiuoti? 1 - vidurkį, 2 - medianą, 0 - abu." Pasirinkus vieną iš variantų programa į ekraną išspausdina deuomenų lentelę. Tačiau, pasirinkus blogą variantą perspėjima, kad pasirinkimas nėra teisingas.



## Naudotos funkcijos:
1. skaitytiDuomenisIsFailo() – nuskaitymo funkcija, kuri įkelia studentų duomenis iš failo į atmintį, tikrina duomenų formatą ir apskaičiuoja galutinius rezultatus kiekvienam studentui.
2. skaitytiDuomenisIsVartotojo() – rankinio duomenų įvedimo funkcija, kuri leidžia vartotojui įvesti studentų vardus, pavardes, namų darbų bei egzamino rezultatus, o jei reikia, sugeneruoja juos automatiškai.
3. string pasirinktiFaila() – leidžia vartotojui pasirinkti, iš kurio failo skaityti duomenis. Grąžina pasirinkto failo pavadinimą.
4. int atsitiktiniaiBalai() – sugeneruoja atsitiktinius balus nuo 0 iki 10 naudojant atsitiktinių skaičių generatorių.
5. void generuotiAtsitiktiniusBalus() – sugeneruoja nurodytą kiekį atsitiktinių namų darbų balų studentui bei vieną atsitiktinį egzamino balą.
6. void Student::skaiciuotiGalutiniVid() – apskaičiuoja studento galutinį balą pagal namų darbų vidurkį ir egzamino balą.
7. void Student::skaiciuotiGalutiniMed() – apskaičiuoja studento galutinį balą pagal namų darbų medianą ir egzamino balą.
8. void spausdintiStudentusVidurki() – atspausdina studentų vardus, pavardes ir galutinius balus, apskaičiuotus pagal namų darbų vidurkį.
9. void spausdintiStudentusMediana() – atspausdina studentų vardus, pavardes ir galutinius balus, apskaičiuotus pagal namų darbų medianą.
10. void spausdintiStudentus() – atspausdina studentų vardus, pavardes ir abu galutinius balus: tiek pagal vidurkį, tiek pagal medianą.
11. bool compareByName() – funkcija, kuri rūšiuoja studentus pagal vardą.


## V0.2

Ši programa apdoroja studentų duomenis, generuoja atsitiktinius studentų įrašus su balais ir skirsto juos į dvi kategorijas: "vargšiukai" (galutinis balas < 5.0) ir "kietiakiai" (galutinis balas ≥ 5.0). Programa taip pat atlieka veikimo spartos analizę, įskaitant failų generavimą, duomenų nuskaitymą, studentų rūšiavimą bei išvedimą į skirtingus failus. 

## Naudotos naujos funkcijos

1. void generuotiStudentuFaila() - funkcija generuoja atsitiktinius studentų duomenis ir įrašo juos į failą. 
2. void rusiuotiStudentus() - funkcija skirsto studentus į dvi grupes pagal jų galutinį balą. Jei galutinis balas mažesnis nei 5.0, studentas priskiriamas "vargšiukams", kitaip – "kietiakiams".
3. void spausdintiStudentusIFaila() - funkcija spausdina studentų duomenis į nurodytą failą. Kiekvieno studento vardas, pavardė ir galutinis balas (vidurkis) yra įrašomi į failą.
4. void rusiuotiStudentusIrIssaugotiIFailus() - funkcija rūšiuoja studentus į dvi kategorijas: "vargšiukai" ir "kietiakiai", o po to išveda juos į du atskirus failus: vargsiukai.txt ir kietiakiai.txt.
5. void laikuMatavimai() - funkcija atlieka laikų matavimus keliais etapais. Ji pirmiausia sugeneruoja studentų duomenis į failą, tada matuoja laiką, kiek užtrunka failo nuskaitymas, studentų rūšiavimas, padalijimas į grupes, ir rezultato išsaugojimas atskiruose failuose.
6. void apdorotiVisusFailus() - funkcija atlieka visų penkių studentų sąrašų generavimą, skaičiuojant laiką kiekvienam failui.

## Programos veikimo paaiškinimas 2

Paleidęs programą naudotojas sulaukia klausimo: ,,ar norite sugeneruoti duomenu failus?" Jei pasirenka, kad nenori (t.y įveda 0), tai toliau naudotojo yra klausiami klausimai, kurie aprašyti programos veikimo paaiškinimo 1 dalyje. Tačiau, jei vartotojas pasirenka, jog nori sugeneruoti failus (t.y įveda 1), tai programa jam leidžia pasirinkti viena iš pateiktų failų variantų. Pasirinkęs, kokį nors iš variantų, jis ekrane išvysta pasirinkto failo analizę.


## Programos sugeneruotų rezultatų pavyzdys

![image](https://github.com/user-attachments/assets/3eaf229d-e584-458c-bd37-b3d253602f6c)
![image](https://github.com/user-attachments/assets/b8fb3e9f-ec24-41c6-9f9f-d3977e23f138)
![image](https://github.com/user-attachments/assets/80ea244c-3a4c-4c70-bcb4-d937c3bc8859)


## V0.3
1. Atliekamas programos spartos tyrimas, kai vietoje std::vector<Studentai> naudojame std::list<Studentai>.
2. Įvedant duomenis ranka, ekrane išspausdinamas objekto saugojimo atmintyje adresas.

## Kompiuterio parametrai:

CPU - Intel(R) Core(TM) i5-10300H CPU @ 2.50GHz

RAM - 8GB

SSD - 477GB

HDD - 932GB

## Rankinio įvedimo rezultatai su atmintyje saugomais adresais (naudojant list konteinerį):

![image](https://github.com/user-attachments/assets/f63673a3-e45a-49e1-bf7e-ea9c4bf19f82)

## Rankinio įvedimo rezultatai su atmintyje saugomais adresais (naudojant vector konteinerį):

![image](https://github.com/user-attachments/assets/9490dc8d-8528-4d44-9939-640deb752baa)


## Kelių testų laikų vidurkiai:

### 1000:

Veiksmas	- Vidurkis (s)

1000 studentų rūšiavimo laikas - 0s

1000 kietiakų išvedimo į failą laikas - 0.003070s

1000 įrašų dalijimo į vargšiukus ir kietiakus laikas - 0.000502s

1000 vargšiukų išvedimo į failą laikas - 0 s 

1000 Failo generavimas - 	0 s

### 10000:

10000 studentų rūšiavimo laikas - 0s 

10000 kietiakų išvedimo į failą laikas - 0.0157431s

10000 įrašų dalijimo į vargšiukus ir kietiakus laikas - 0.0157247s

10000 vargšiukų išvedimo į failą laikas - 0s 

10000Failo generavimas - 	0,0156177 s


### 100000:

100000 studentų rūšiavimo laikas - 0,0941269s 

100000 kietiakų išvedimo į failą laikas - 0.109746s

100000 įrašų dalijimo į vargšiukus ir kietiakus laikas - 0.109746s

100000 vargšiukų išvedimo į failą laikas - 0,0654928s 

100000 Failo generavimas - 	0,167111 s

### 1000000:

1000000 studentų rūšiavimo laikas - 1,05137s 

1000000 kietiakų išvedimo į failą laikas - 0,736714s

1000000 įrašų dalijimo į vargšiukus ir kietiakus laikas - 1,13003s

1000000 vargšiukų išvedimo į failą laikas - 0,502124s 

1000000 Failo generavimas - 	1,59979 s

### 10000000:

1000000 studentų rūšiavimo laikas - 18,4297s 

1000000 kietiakų išvedimo į failą laikas - 14,4601s

1000000 įrašų dalijimo į vargšiukus ir kietiakus laikas - 37,1144s

1000000 vargšiukų išvedimo į failą laikas - 6,76164s 

10000000 Failo generavimas - 	18,7489 s


## Išvados

Kai naudojamas listas, o ne vektorius studentai į vargšiukus ir kietiakus padalinami greičiau. Tačiau, tai yra vienintelis aspektas, kuriame skaičiuojant didelių duomenų failų laikus listas yra pranašesnis už vektorių, nes tiek duomenų generavime, tiek išvedime, tiek nuskaityme, su vektoriais veiksmai atliekami kur kas greičiau nei su listais.


## V1.0

Realizuotos trys studentų skirstymo į du failus (vargšiukus ir kietiakus) strategijos naudojant tiek vector, tiek list konteinerius.

## Strategijos

1 Strategija: naudojamas bendras studentų konteineris (vector arba list), kuris skaidomas į du naujus konteinerius: "vargšiukai" ir "kietiakai". 

2 Strategija: sukuriamas tik vienas naujas konteineris "vargšiukai", į kurį perkeliami visi nepažangūs studentai, tuo pat metu ištrinant juos iš bendro studentų konteinerio. 

3 Strategija: optimizuota skaidymo strategija, pritaikant greičiausiai veikiančius metodus iš pirmosios arba antrosios strategijos, siekiant padidinti veikimo efektyvumą naudojant konteinerių operacijas. Vektoriams naudotas std::partition, o listam - std::remove_if metodas.

## Laikai

### 10000:

| Veiksmas                              | 2_strategija vektoriai | 2_strategija listai |  vektoriai su std::partition | listai su  std::remove_if |
|---------------------------------------|------------------------|---------------------|------------------------------|---------------------------|
| Nuskaitymo iš failo laikas (s)        | 0,0468657              | 0,0657071           | 0,0316316                    | 0,0468633                 |
| Rūšiavimo laikas (s)                  | 0                      | 0                   | 0                            | 0,0156217                 |
| Dalijimo į dvi kategorijas laikas (s) | 0,78425                | 0                   | 0                            | 0                         |
| Vargšiukų išvedimo į failą laikas (s) | 0,0156203              | 0,0156247           | 0,0156255                    | 0                         |
| Kietiakų išvedimo į failą laikas (s)  | 0                      | 0,0312425           | 0,0156213                    | 0                         |


### 100000:

| Veiksmas                              | 2_strategija vektoriai | 2_strategija listai | vektoriai su std::partition | listai su  std::remove_if |
|---------------------------------------|------------------------|---------------------|-----------------------------|---------------------------|
| Nuskaitymo iš failo laikas (s)        | 0,296614               | 0,548746            | 0,298046                    | 0,552085                  |
| Rūšiavimo laikas (s)                  | 0,142994               | 0,0628796           | 0,141399                    | 0,0599154                 |
| Dalijimo į dvi kategorijas laikas (s) | 77,9162                | 0,0624856           | 0,0312483                   | 0,0785116                 |
| Vargšiukų išvedimo į failą laikas (s) | 0,0468338              | 0,0594771           | 0,0468614                   | 0,046863                  |
| Kietiakų išvedimo į failą laikas (s)  | 0,0629341              | 0,0622636           | 0,0785039                   | 0,0785034                 |


### 1000000:

| Veiksmas                              | 2_strategija vektoriai | 2_strategija listai | vektoriai su std::partition | listai su  std::remove_if |
|---------------------------------------|------------------------|---------------------|-----------------------------|---------------------------|
| Nuskaitymo iš failo laikas (s)        | 3,87373                | 4,77311             | 2,52475                     | 4,76952                   |
| Rūšiavimo laikas (s)                  | 1,91405                | 0,873119            | 1,60056                     | 0,826462                  |
| Dalijimo į dvi kategorijas laikas (s) |    -                   | 0,518548            | 0,266695                    | 0,663374                  |
| Vargšiukų išvedimo į failą laikas (s) |    -                   | 0,467323            | 0,423231                    | 0,423652                  |
| Kietiakų išvedimo į failą laikas (s)  |    -                   | 0,670398            | 0,597601                    | 0,690351                  |


### 10000000:

| Veiksmas                              | 2_strategija vektoriai | 2_strategija listai | vektoriai su std::partition | listai su  std::remove_if |
|---------------------------------------|------------------------|---------------------|-----------------------------|---------------------------|
| Nuskaitymo iš failo laikas (s)        | 31,641                 | 58,4726             | 32,0403                     | 57,5271                   |
| Rūšiavimo laikas (s)                  | 23,9927                | 15,0123             | 24,2912                     | 14,0141                   |
| Dalijimo į dvi kategorijas laikas (s) |    -                   | 21,4616             | 3,58443                     | 20,7895                   |
| Vargšiukų išvedimo į failą laikas (s) |    -                   | 6,06486             | 6,08612                     | 6,93211                   |
| Kietiakų išvedimo į failą laikas (s)  |    -                   | 9,18397             | 8,21381                     | 9,10787                   |

