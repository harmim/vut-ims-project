# Modelování a simulace - Projekt

#### Autoři
- Dominik Harmim <xharmi00@stud.fit.vutbr.cz>
- Vojtěch Hertl <xhertl04@stud.fit.vutbr.cz>

#### Simulační studie (dokumentace)
[./documentation.pdf](./documentation.pdf)

#### Zdrojové soubory simulačního modelu
- `./src/*.cpp`
- `./src/*.hpp`

#### Překlad simulačního modelu
```bash
$ make
```
nebo
```bash
$ make build
```
nebo
```bash
$ make ims-project
```

#### Spuštění simulačního module
Spuštění s výchozími argumenty:
```bash
$ make run
```
Příklad spuštění s argumenty:
```bash
$ make run ARGS='--cars 20 --food 20000'
```
