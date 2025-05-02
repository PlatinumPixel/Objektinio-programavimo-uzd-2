# Objektinio-programavimo-uzd

Ši programa del skirtingu konteineriu laikų testavimų naudojant struktūras
Kad paleist programa reikia tik paleisti run.bat faila


CPU: AMD Ryzen 7 8845, 8 Cores, 3,8 GHZ<br>
RAM: 16 GB, 5600 MT/s<br>
SSD NVMe <br>

| Palyginimas su struct |             |              |            |          |
|-----------------------|-------------|--------------|------------|----------|
|                       |             |              |            |          |
| 1000000               | Nuskaitymas | Išrušiavimas | Rikiavimas | Iš viso  |
| Struct                | 2.83606     | 0.32922      | 1.80675    | 4.97203  |
| Class                 | 3.0605      | 0.4786       | 2.9328     | 6.4719   |
|                       |             |              |            |          |
| 10000000              |             |              |            |          |
| Struct                | 28.1194     | 4.53599      | 21.0747    | 53.73009 |
| Class                 | 32.5148     | 4.6985       | 36.9629    | 74.1762  |
<br>


| O1       |             |              |            |              |         |              |
|----------|-------------|--------------|------------|--------------|---------|--------------|
|          | Nuskaitymas | Išrušiavimas | Rikiavimas | Spausdinimas | Iš viso | Failoo Dydis |
| 1000000  | 3.0605      | 0.4786       | 2.9328     | 4.4443       | 10.916  | 256          |
| 10000000 | 32.5148     | 4.6985       | 36.9629    | 45.7464      | 119.923 |              |
<br>

| O2       | Nuskaitymas | Išrušiavimas | Rikiavimas | Spausdinimas | Iš viso | Failo Dydis |
|----------|-------------|--------------|------------|--------------|---------|-------------|
| 1000000  | 1.4488      | 0.19         | 0.5033     | 4.2815       | 6.4235  | 252         |
| 10000000 | 16.5359     | 1.7361       | 6.7056     | 49.511       | 74.4885 |             |

<br>
| O3       | Nuskaitymas | Išrušiavimas | Rikiavimas | Spausdinimas | Iš viso | Failo Dydis |
|----------|-------------|--------------|------------|--------------|---------|-------------|
| 1000000  | 1.4647      | 0.1809       | 0.5059     | 4.344        | 6.4953  | 272         |
| 10000000 | 15.5423     | 1.7754       | 7.0386     | 44.9865      | 69.3427 |             |
<br>


![alt text](images/image.png)
<br>
