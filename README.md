# Objektinio-programavimo-uzd

Ši programa del skirtingu konteineriu laikų testavimų naudojant struktūras
Kad paleist programa reikia tik paleisti run.bat faila


CPU: AMD Ryzen 7 8845, 8 Cores, 3,8 GHZ<br>
RAM: 16 GB, 5600 MT/s<br>
SSD NVMe <br>

------------------1.2--------------------<br>

Studentas klasę galima rasti "Struktura.h" faile

Įvestis/Išvestis iš Studentas klasės: readFromConsole metodas (Įvesties metodas iš konsolės):

Pirmiausia prašomas studento vardą ir pavardę. Po to, vartotojas prašomas įvesti studento pažymius, kol nebus įvestas N (tai bus ženklas, kad įvedimas baigiasi). Galiausiai, prašoma įvesti egzamino pažymį, kuris bus paskutinis įvestas duomenų taškas.

readFromFile metodas (Įvesties metodas iš failo):

Šis metodas skaito informaciją iš failo. Failo struktūra turi būti tokia, kad kiekvienas studento įrašas būtų eilutėje su vardu, pavarde ir pažymiais.
(pirma eilutė neskaitoma nes skirta duomenų pavadinimams dėl aiškumo)

pvz:
Vardas         Pavarde        ND1    ND2    ND3    ND4    ND5    ND6    ND7    ND8    ND9    ND10   ND11   ND12   ND13   ND14   ND15   Egz.
Vardas1        Pavarde1       9      9      8      1      9      1      9      4      1      3      2      5      3      10     7      4      
Vardas2        Pavarde2       1      8      5      10     8      1      3      7      4      9      8      4      7      8      2      4 

Veikimas:

Pirmiausia, metodas nuskaitys studento vardą ir pavardę. Tada jis nuskaitys visus pažymius ir įrašys juos į pazymiai vektorių. Paskutinis nuskaitytas pažymys bus laikomas egzamino pažymiu, ir jis bus išimtas iš pažymių sąrašo (naudojant pop_back).

Išvedimo operatorius <<: Šis operatorius (operator<<) naudojamas objektų Studentas duomenų išvedimui tiek į konsolę, tiek į failą. Šis operatorius priima std::ostream tipo srautą (tai gali būti tiek std::cout (konsolė), tiek std::ofstream (failas))

Išvedimas formatuojamas taip:
Vardas              Pavarde        Galutinis(vid.) / Galutinis(med.)
--------------------------------------------------------------------
Antanas             Janauskas      5.00               5.00
Antanas             Stankevicius   2.00               2.00

