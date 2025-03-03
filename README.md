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


|                                                 | Pirmas bandymas | Antras bandymas | Trečias bandymas | Ketvirtas bandymas | Penktas bandymas | Vidurkis|
|-------------------------------------------------|------|-----------------|------------------|-----------------|-----------------|-----------------|
| Duomenų nuskaitymas iš failo                    | 0.014 | 0.014           | 0.014            | 0.014| 0.014| 0.014|
| Duomenų rūšiavimas didėjimo tvarka              | 0.02 | 0.02          | 0.02             | 0.014| 0.014| 0.014|
| Studentų rūšiavimas į dvi kategorijas           |  0.001 |  0.001        | 0.001            | 0.07| 0.071 | 0.71|
| Surūšiuotų studentų išvedimas į kietekų failą   | 0.003| 0.003         | 0.003            | 0.619| 0.616 | 0.6318|
| Surūšiuotų studentų išvedimas į vagršiukų failą |  0.002 | 0.002          | 0.002            | 6.2| 6.238| 6.2356|
| Visos programos veikimo laikas                  | 1.571 | 1.553        | 1.894           | 68.262| 68.326| 68.7766|

10000 įrašų:

|                                                 | Pirmas bandymas | Antras bandymas | Trečias bandymas | Ketvirtas bandymas | Penktas bandymas | Vidurkis|
|-------------------------------------------------|------|----------------|----------------|-----------------|-----------------|-----------------|
| Duomenų nuskaitymas iš failo                    | 0.057 | 0.057| 0.058| 0.014| 0.014| 0.014|
| Duomenų rūšiavimas didėjimo tvarka              | 0.099 | 0.099 | 0.098| 0.014| 0.014| 0.014|
| Studentų rūšiavimas į dvi kategorijas           | 0.007 |  0.007 |  0.007 | 0.07| 0.071 | 0.71|
| Surūšiuotų studentų išvedimas į kietekų failą   | 0.015| 0.013|  0.012 | 0.619| 0.616 | 0.6318|
| Surūšiuotų studentų išvedimas į vagršiukų failą | 0.011 |  0.009 |  0.009 | 6.2| 6.238| 6.2356|
| Visos programos veikimo laikas                  | 1.571 | 1.553| 1.894 | 68.262| 68.326| 68.7766|


100000 įrašų:

|                                                 | Pirmas bandymas | Antras bandymas | Trečias bandymas | Ketvirtas bandymas | Penktas bandymas | Vidurkis|
|-------------------------------------------------|------|-----------------|-----------------|-----------------|-----------------|-----------------|
| Duomenų nuskaitymas iš failo                    |  0.379 |  0.377 |  0.378| 0.014| 0.014| 0.014|
| Duomenų rūšiavimas didėjimo tvarka              |  0.626 | 0.59 | 0.587| 0.014| 0.014| 0.014|
| Studentų rūšiavimas į dvi kategorijas           | 0.062|  0.063 | 0.063 | 0.07| 0.071 | 0.71|
| Surūšiuotų studentų išvedimas į kietekų failą   | 0.126| 0.126 | 0.124 | 0.619| 0.616 | 0.6318|
| Surūšiuotų studentų išvedimas į vagršiukų failą | 0.09 | 0.089 | 0.089 | 6.2| 6.238| 6.2356|
| Visos programos veikimo laikas                  |  2.002 | 1.861|  1.262| 68.262| 68.326| 68.7766|

1000000 įrašų:

|                                                 | Pirmas bandymas | Antras bandymas | Trečias bandymas | Ketvirtas bandymas | Penktas bandymas | Vidurkis|
|-------------------------------------------------|------|-----------------|-----------------|-----------------|-----------------|-----------------|
| Duomenų nuskaitymas iš failo                    | 3.818 | 3.7 | 3.797| 0.014| 0.014| 0.014|
| Duomenų rūšiavimas didėjimo tvarka              |  5.846 | 5.778 |  5.755| 0.014| 0.014| 0.014|
| Studentų rūšiavimas į dvi kategorijas           | 0.694 |   0.699 |  0.695 | 0.07| 0.071 | 0.71|
| Surūšiuotų studentų išvedimas į kietekų failą   |  1.288| 1.314 |  1.355| 0.619| 0.616 | 0.6318|
| Surūšiuotų studentų išvedimas į vagršiukų failą | 0.901 | 0.973 | 0.891 | 6.2| 6.238| 6.2356|
| Visos programos veikimo laikas                  | 13.79|  13.515| 12.675| 68.262| 68.326| 68.7766|


10000000 įrašų:

|                                                 | Pirmas bandymas | Antras bandymas | Trečias bandymas | Ketvirtas bandymas | Penktas bandymas | Vidurkis|
|-------------------------------------------------|------|-----------------|-----------------|-----------------|-----------------|-----------------|
| Duomenų nuskaitymas iš failo                    | 40.703 | 40.693 | 40.651| 0.014| 0.014| 0.014|
| Duomenų rūšiavimas didėjimo tvarka              |  60.468 | 60.957 | 60.41| 0.014| 0.014| 0.014|
| Studentų rūšiavimas į dvi kategorijas           | 6.554 | 6.594 |  6.566 | 0.07| 0.071 | 0.71|
| Surūšiuotų studentų išvedimas į kietekų failą   | 14.762| 15.332 |  15.472 | 0.619| 0.616 | 0.6318|
| Surūšiuotų studentų išvedimas į vagršiukų failą | 9.717| 9.702 | 9.959 | 6.2| 6.238| 6.2356|
| Visos programos veikimo laikas                  | 135.063 | 135.857| 134.898 | 68.262| 68.326| 68.7766|

