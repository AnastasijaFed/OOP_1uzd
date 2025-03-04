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

