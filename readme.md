***v.pradinė***
1. Sukurta struktūra, kuri aprašo studento duomenis.
2. Sukurtos funkcijos leidžiančios vartotojui įvesti duomenis ranka, pasirinkti namų darbų įvedimo būdą.
3. Sukurtos funkcijos, kurios vartotojui pateikus duomenis pasirinktinai apskaičiuoja vidurkį, medianą arba abi reikšmės.

***v0.1***
1. Pridėta duomenų nuskaitymo iš failo galimybė.
2. Pridėta galimybė pasirinkti vieną iš keturių pateiktų failų, kurį norima nuskaityti.
3. Pridėtas studentų rūšiavimas pagal vardą.


***Programos veikimo paaiškinimas***
1. Paleidus programą vartotojas turi galimybę pasirinkti, ar nori pats įvesti duomenis ar nori juos nuskaityti iš failo ( turi įvesti 1, jei nori nuskaityti duomenis iš failo arba 0, jei nori juos įvesti pats).
   - Jeigu įvedamas sąlygoje nenurodytas variantas, programa išmeta klaidą bei pasiūlo bandyti iš naujo.
   - Pasirinkus, jog duomenis norite nuskaityti iš failo, vartotojui pasiūlomi 4 skirtingi failų variantai bei leidžiama pasirinkti norimą. Jei įvedamas ne atitinkamą failą žymintis simbolis (šiuo atveju skaičius nuo 1 iki 4), tai automatiškai skaičiavimams parenkamas kursiokai.txt failas. Toliau vartotojui leidžiama pasirinkti, ka nori apskaičiuoti (1 - vidurkį, 2 - medianą, 0 - abu). Vėlgi, jei įvedamas sąlygoje nenurodytas simbolis išspausdinama klaida, jog pasirinkimas buvo neteisingas. Teisingu atveju - išspausdinama duomenų lentelė. 
   - Vartotojui pasirinkus rankinio įvedimo atvejį, jo paklausiama, kelių studentų duomenis norės pateikti (galimas pasirinkimas - bet koks sveikasis skaičius). Pasirinkus norimą studentų skaičių, paprašoma pateikti jų visų duomenis (vardą, pavardę, namų darbų pažymius ir egzamino pažymį). Prieš vedant namų darbų pažymius vartotojo paklausiama, ar jis juos ir egzamino pažymį nori suvesti pats ar nori, kad programa pažymius sugeneruotų automatiškai. Jei pasirenka, kad duomenys būtų sugeneruoti automatiškai, tai paklausiama, kiek namų darbų pažymių sugeneruoti. Na, o jei pasirenka, jog duomenis nori įvesti pats, tai paprašoma suvesti visus pažymius bei egzamino rezultatą. Programa supranta, kad suvesti visi pažymiai, kai naudotojas įveda -1. Svarbu, kad namų darbų ir egzamino pažymys turi būti įvedamas dešimtbalėje skalėje. Kai pažymiai būna suvesti arba sugeneruoti automatiškai, tai tada paklausiamas paskutinis klausimas: ,,Ką norite apskaičiuoti? 1 - vidurkį, 2 - medianą, 0 - abu." Pasirinkus vieną iš variantų programa į ekraną išspausdina deuomenų lentelę. Tačiau, pasirinkus blogą variantą perspėjima, kad pasirinkimas nėra teisingas.



***Naudotos funkcijos:***
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
