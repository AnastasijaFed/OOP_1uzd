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

Kiekvienas žingsnis taip pat buvo kartojamas po 5 kartus ir pateiktas šių bandymų vidurkis.

