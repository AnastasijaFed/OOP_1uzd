v1.0
Šio tyrimo tikslas yra ištirti programos spartą naudojant skirtingus konteinerius: vector, list, deque. 
Atlikti skirtingi veiksmai su konteineriais ir buvo matuojamas atlikimo veikimo laikas, pavaizduotas lentelėse:

1. Nuskaitymas iš failo į atitinkamą konteinerį.
   
    1.1. Rezultatai skaitymo į List konteinerį:

   | Įrašų skaičius faile | Pirmas bandymas | Antras bandymas | Trečias bandymas | Ketvirtas bandymas | Penktas bandymas | Vidurkis|
   |---------|------|-----------------|-----------------|-----------------|-----------------|-----------------|
   | 1000  | 0.001 | 0.002 | 0.002| 0.002| 0.002| |
   | 10000 | 0.018 |  0.019 | 0.022 | 0.018| 0.019 | |
   | 100000 | 0.195| 0.22 |  0.2| 0.216| 0.211 | |
   | 1000000 | 2.023 | 2.013 | 2.009 | 2.012| 2.018| |
   | 10000000| 20.616 | 20.63| 20.564 | 20.446| 20.402| |

   **1.2. Rezultatai skaitymo į Deque konteinerį:**

   | Įrašų skaičius faile | Pirmas bandymas | Antras bandymas | Trečias bandymas | Ketvirtas bandymas | Penktas bandymas | Vidurkis|
   |---------|------|-----------------|-----------------|-----------------|-----------------|-----------------|
   | 1000  | 0.002| 0.002 | 0.002| 0.002| 0.002| |
   | 10000 | 0.02 |  0.021 | 0.021 | 0.021| 0.021 | |
   | 100000 | 0.214| 0.216 |  0.223| 0.219| 0.224 | |
   | 1000000 | 2.239 | 2.173 | 2.17 | 2.168| 2.173| |
   | 10000000 | 27.198 | 25.904| 25.995 | 26.309| 26.451| |
   1.3 Rezultatai skaitymo į Vector konteinerį:

| Įrašų skaičius faile | Pirmas bandymas | Antras bandymas | Trečias bandymas | Ketvirtas bandymas | Penktas bandymas | Vidurkis|
   |---------|------|-----------------|-----------------|-----------------|-----------------|-----------------|
| 1000  |  0.014           | 0.014           | 0.014            | 0.013| 0.014| 0.0138   |
| 10000 | 0.057           | 0.057           | 0.058            | 0.063| 0.064| 0.0598|
| 100000 | 0.379 |  0.377 |  0.378| 0.627| 0.839| 0.52|
| 1000000 | 3.818 | 3.7 | 3.797| 7.434| 6.293| 5.0084|
| 10000000 | 40.703 | 40.693 | 40.651| 68.402| 66.579| 51.4056|

2. Studentų rūšiavimas didėjimo tvarka (pagal galutinį pažymį iš vidurkio)
   
   2.1 Rūšiavimas su List:

| Įrašų skaičius faile | Pirmas bandymas | Antras bandymas | Trečias bandymas | Ketvirtas bandymas | Penktas bandymas | Vidurkis|
   |---------|------|-----------------|-----------------|-----------------|-----------------|-----------------|
| 1000  |  6.8375e-05          | 5.4833e-05         | 5.5208e-05            | 5.5625e-05| 5.425e-05| 0.0138   |
| 10000 | 0.000776459         | 0.000714625         | 0.000778375           |0.000696541| 0.000743917| 0.0598|
| 100000 | 0.0101778 | 0.0134357 |  0.0186094| 0.0109893|0.0101133| 0.52|
| 1000000 | 0.413999 | 0.396489| 0.437618| 0.505107| 0.436495| 5.0084|
| 10000000 | 8.34264 | 8.01193| 8.17679| 8.01488| 8.13933| 51.4056|
2.2. Rūšiavimas su Deque:

| Įrašų skaičius faile | Pirmas bandymas | Antras bandymas | Trečias bandymas | Ketvirtas bandymas | Penktas bandymas | Vidurkis|
|---------|------|-----------------|-----------------|-----------------|-----------------|-----------------|
| 1000  |  1.792e-06      |1.917e-06         | 1.875e-06           | 1.916e-06s| 1.916e-06| 0.0138   |
| 10000 | 6.5625e-05      | 7.3292e-05         | 3e-05           | 6.0708e-05| 6.8958e-05| 0.0598|
| 100000 | 0.00140246 | 0.00144383 |  0.00110646| 0.00239883| 0.00141058| 0.52|
| 1000000 | 0.105023 | 0.0354815|0.0365577| 0.0287554| 0.0330828| 5.0084|
| 10000000 | 1.07304 | 0.380618| 0.399486| 0.402701|  0.349551| 51.4056|

2.3. Rūšiavimas su Vector

| Įrašų skaičius faile | Pirmas bandymas | Antras bandymas | Trečias bandymas | Ketvirtas bandymas | Penktas bandymas | Vidurkis|
|---------|------|-----------------|-----------------|-----------------|-----------------|-----------------|
| 1000  | 0.001           | 0.001           | 0.001            | 0.001| 0.001| 0.018    |
| 10000 | 0.012          | 0.014           | 0.014            | 0.014| 0.093| 0.0968|
| 100000 | 0.135 | 0.144 |  0.142| 0.148| 0.141| 0.52|
| 1000000 | 1.511 |1.436| 1.393| 1.475| 1.452| 5.0084|
| 10000000 | 18.33 | 17.973| 17.974| 17.814| 17.834| 51.4056|

3. Įrašų dalijimas į du konteinerius

   3.1. Įrašų dalijimas į List

| Įrašų skaičius faile | Pirmas bandymas | Antras bandymas | Trečias bandymas | Ketvirtas bandymas | Penktas bandymas | Vidurkis|
|---------|------|-----------------|-----------------|-----------------|-----------------|-----------------|
| 1000  | 0.001           | 0.001           | 0.001            | 0.001| 0.001| 0.018    |
| 10000 | 0.012          | 0.014           | 0.014            | 0.014| 0.093| 0.0968|
| 100000 | 0.135 | 0.144 |  0.142| 0.148| 0.141| 0.52|
| 1000000 | 1.511 |1.436| 1.393| 1.475| 1.452| 5.0084|
| 10000000 | 18.33 | 17.973| 17.974| 17.814| 17.834| 51.4056|

3.2. Įrašų dalijimas į Deque

| Įrašų skaičius faile | Pirmas bandymas | Antras bandymas | Trečias bandymas | Ketvirtas bandymas | Penktas bandymas | Vidurkis|
|---------|------|-----------------|-----------------|-----------------|-----------------|-----------------|
| 1000  | 0.003          | 0.001           | 0.001            | 0.001| 0.001| 0.018    |
| 10000 | 0.010          | 0.014           | 0.014            | 0.014| 0.093| 0.0968|
| 100000 | 0.105 | 0.144 |  0.142| 0.148| 0.141| 0.52|
| 1000000 | 2.507 |1.436| 1.393| 1.475| 1.452| 5.0084|
| 10000000 | 18.33 | 17.973| 17.974| 17.814| 17.834| 51.4056|



v0.4
Atlikti du tyrimai programos veikimo greičio analizei.
Pirmasis tyrimas skirtas darbo su failais (failų sukurimas ir jo uždarymas) spartos analizei.
Matuojamas skirtingo dydžio failų sukūrimo laikas. Tyrimo patikimumui bandymas buvo atliekamas penkis kartus. Bandymų rezultatai yra pateikti lentelėje (laikas skaičiuojamas sekundėmis):

| Failo pavadinimas | Pirmas bandymas | Antras bandymas | Trečias bandymas | Ketvirtas bandymas | Penktas bandymas | Vidurkis|
|-------------------|------|-----------------|-----------------|-----------------|-----------------|-----------------|
| students1000.txt     | 0.014 | 0.013 | 0.014| 0.014| 0.014| 0.014|
| students10000.txt     | 0.071 |  0.071 | 0.071 | 0.07| 0.071 | 0.71|
| students100000.txt     | 0.627| 0.622 |  0.63 | 0.619| 0.616 | 0.6318|
| students1000000.txt     | 6.186 | 6.207 | 6.347 | 6.2| 6.238| 6.2356|
| students10000000.txt   | 68.331 | 69.294| 69.67 | 68.262| 68.326| 68.7766|

Antrasis tyrimas skirtas duomenų apdorojimo spartos analizei. Atliekami šie veiksmai:

1. Duomenų nuskaitymas iš failo
2. Studentų rūšiavimas į dvi kategorijas
3. Surūšiuotų studentų išvedimą į naujus failus.

Be to, buvo matuojamas visos programos veikimo laikas.Kiekvienas žingsnis taip pat buvo kartojamas po 5 kartus ir pateiktas šių bandymų vidurkis. Rezultatai pateikiami lentelėje (laikas pateikiamas sekundėmis):

1000 įrašų:


|                                                 | Pirmas bandymas | Antras bandymas | Trečias bandymas | Ketvirtas bandymas | Penktas bandymas | Vidurkis |
|-------------------------------------------------|-----------------|-----------------|------------------|-----------------|-----------------|----------|
| Duomenų nuskaitymas iš failo                    | 0.014           | 0.014           | 0.014            | 0.013| 0.014| 0.0138   |
| Duomenų rūšiavimas didėjimo tvarka              | 0.02            | 0.02            | 0.02             | 0.015| 0.015| 0.018    |
| Studentų rūšiavimas į dvi kategorijas           | 0.001           | 0.001           | 0.001            | 0.001| 0.001 | 0.001    |
| Surūšiuotų studentų išvedimas į kietekų failą   | 0.003           | 0.003           | 0.003            | 0.003| 0.003 | 0.003    |
| Surūšiuotų studentų išvedimas į vagršiukų failą | 0.002           | 0.002           | 0.002            | 0.002| 0.002| 0.002    |
| Visos programos veikimo laikas                  | 0.04            | 0.04            | 0.04             |  0.036|  0.037| 0.0386 |

10000 įrašų:

|                                                 | Pirmas bandymas | Antras bandymas | Trečias bandymas | Ketvirtas bandymas | Penktas bandymas | Vidurkis|
|-------------------------------------------------|-----------------|-----------------|------------------|-----------------|----------------|-----------------|
| Duomenų nuskaitymas iš failo                    | 0.057           | 0.057           | 0.058            | 0.063| 0.064| 0.0598|
| Duomenų rūšiavimas didėjimo tvarka              | 0.099           | 0.099           | 0.098            | 0.095| 0.093| 0.0968|
| Studentų rūšiavimas į dvi kategorijas           | 0.007           | 0.007           | 0.007            | 0.011| 0.011 | 0.0086|
| Surūšiuotų studentų išvedimas į kietekų failą   | 0.015           | 0.013           | 0.012            | 0.021| 0.02 |  0.0162|
| Surūšiuotų studentų išvedimas į vagršiukų failą | 0.011           | 0.009           | 0.009            | 0.015|  0.014| 0.0116|
| Visos programos veikimo laikas                  | 0.189           | 0.185           | 0.184            | 0.036| 0.037| 0.1262|


100000 įrašų:

|                                                 | Pirmas bandymas | Antras bandymas | Trečias bandymas | Ketvirtas bandymas | Penktas bandymas | Vidurkis|
|-------------------------------------------------|------|-----------------|-----------------|-----------------|-----------------|-----------------|
| Duomenų nuskaitymas iš failo                    |  0.379 |  0.377 |  0.378| 0.627| 0.839| 0.52|
| Duomenų rūšiavimas didėjimo tvarka              |  0.626 | 0.59 | 0.587| 0.957| 0.953| 0.7426|
| Studentų rūšiavimas į dvi kategorijas           | 0.062|  0.063 | 0.063 | 0.103|  0.101 |0.0784|
| Surūšiuotų studentų išvedimas į kietekų failą   | 0.126| 0.126 | 0.124 | 0.218| 0.218 | 0.1624|
| Surūšiuotų studentų išvedimas į vagršiukų failą | 0.09 | 0.089 | 0.089 | 0.151| 0.145| 0.1128|
| Visos programos veikimo laikas                  |  2.002 | 1.861|  1.262|  2.088| 2.29| 1.9006|

1000000 įrašų:

|                                                 | Pirmas bandymas | Antras bandymas | Trečias bandymas | Ketvirtas bandymas | Penktas bandymas | Vidurkis|
|-------------------------------------------------|------|-----------------|-----------------|-----------------|-----------------|-----------------|
| Duomenų nuskaitymas iš failo                    | 3.818 | 3.7 | 3.797| 7.434| 6.293| 5.0084|
| Duomenų rūšiavimas didėjimo tvarka              |  5.846 | 5.778 |  5.755| 10.024| 9.641| 7.4088|
| Studentų rūšiavimas į dvi kategorijas           | 0.694 |   0.699 |  0.695 |1.135| 1.12 | 0.8686|
| Surūšiuotų studentų išvedimas į kietekų failą   |  1.288| 1.314 |  1.355| 2.15| 2.061 | 1.6336|
| Surūšiuotų studentų išvedimas į vagršiukų failą | 0.901 | 0.973 | 0.891 | 1.477| 1.458| 1.14|
| Visos programos veikimo laikas                  | 13.79|  13.515| 12.675| 22.511| 20.863| 16.6708|


10000000 įrašų:

|                                                 | Pirmas bandymas | Antras bandymas | Trečias bandymas | Ketvirtas bandymas | Penktas bandymas | Vidurkis|
|-------------------------------------------------|------|-----------------|-----------------|-----------------|-----------------|-----------------|
| Duomenų nuskaitymas iš failo                    | 40.703 | 40.693 | 40.651| 68.402| 66.579| 51.4056|
| Duomenų rūšiavimas didėjimo tvarka              |  60.468 | 60.957 | 60.41|  97.318| 96.196| 75.0698|
| Studentų rūšiavimas į dvi kategorijas           | 6.554 | 6.594 |  6.566 | 10.4| 10.341| 8.091|
| Surūšiuotų studentų išvedimas į kietekų failą   | 14.762| 15.332 |  15.472 | 22.336| 21.592 | 17.8988|
| Surūšiuotų studentų išvedimas į vagršiukų failą | 9.717| 9.702 | 9.959 | 16.731| 16.377| 12.4972|
| Visos programos veikimo laikas                  | 135.063 | 135.857| 134.898 | 218.088| 213.962| 167.5736|

