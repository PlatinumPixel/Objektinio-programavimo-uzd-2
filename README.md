# Objektinio-programavimo-uzd

Ši programa del skirtingu konteineriu laikų testavimų naudojant struktūras
Kad paleist programa reikia tik paleisti setup.msi faila.
Tada atsiras ant desktop shortcut į exe, taip pat per starmenu bus pasiekiama
Programa atsiunčiama į Programfiles(x86)/VU/NojusGirdziuna/


CPU: AMD Ryzen 7 8845, 8 Cores, 3,8 GHZ<br>
RAM: 16 GB, 5600 MT/s<br>
SSD NVMe <br>

3.0

Šioje Programoje sukurta ir naudojama Vektoriaus klase<br>
Joje implementuota<br>
Construktoriai:<br>
Vektorius<typename> v       //Sukuria tuščia vektoriu<br>
Vektorius<typename> v(n)    //Sukuria tuščia vektoriu n dydžio<br>
Vektorius<typename> v(n,k)  //Sukuria vektoriu n dydžio, užpildyta k<br>
Vektorius<typename> v({1,2,3}) //Sukuria vektoriu kuriame yra elementai 1,2,3<br>

Destruktorius<br>
copy construktorius ir operacija<br>
move consturktorius ir operacija<br>

swap<br>
assign<br> 
shrink_to_fit<br>
erase<br>
insert<br>
emplace<br>
push_back<br>
pop_back<br>
size<br>
capacity<br>
empty<br>
clear<br>
reserve<br>
resize<br>
at<br>
[] operatorius<br>
==, !=,<br>
<, <=, >, >=<br>
begin, cbegin, rbegin, rcbegin<br>
end, cend, rend, rcend,<br>
front,<br>
back, <br>
įprasta vektoriaus data() funckija pervardinta į storage(),<br>

Daugiau dokumentuotas klase yra pdf formatu

std::vector ir Vektoriaus užpildymo laiko testavimas
<br>
|           | std:vector | Vektorius | std Reallocations | Vektoriaus Reallocations |
|-----------|------------|-----------|-------------------|--------------------------|
| 10000     | 0.000517   | 0.000272  | 15                | 15                       |
| 100000    | 0.003779   | 0.001009  | 18                | 18                       |
| 1000000   | 0.035981   | 0.010968  | 21                | 21                       |
| 10000000  | 0.287432   | 0.107743  | 25                | 25                       |
| 100000000 | 3.30311    | 1.23185   | 28                | 28                       |
<br>
Sukurto vektoriaus spartumas<br>

| Vektorius |             |              |              |          |
|-----------|-------------|--------------|--------------|----------|
|           | Nuskaitymas | Išrušiavimas | Išrikiavimas | Iš viso  |
| 1000      | 0.043964    | 0.00224      | 0.0056341    | 0.051769 |
| 10000     | 0.444661    | 0.0309179    | 0.049972     | 0.525462 |
| 100000    | 4.5369      | 0.22554      | 0.558844     | 5.32118  |
| 1000000   | 44.3652     | 2.31514      | 5.91125      | 52.5915  |
| 10000000  | 490.645     | 47.8489      | 61.81        | 600.3    |
<br>
std::vector spartumas<br>

| std Vector |             |              |              |          |
|------------|-------------|--------------|--------------|----------|
|            | Nuskaitymas | Išrušiavimas | Išrikiavimas | Iš viso  |
| 1000       | 0.0644308   | 0.0022129    | 0.0074612    | 0.074028 |
| 10000      | 0.649687    | 0.0372766    | 0.0914448    | 0.776228 |
| 100000     | 6.62527     | 0.302673     | 0.828665     | 7.75646  |
| 1000000    | 65.8765     | 2.76999      | 9.14181      | 77.7871  |
| 10000000   | 697.445     | 33.2529      | 95.7009      | 826.395  |<br>
