## Merge и Tim sort
[![CMake](https://github.com/Algorithms-and-Data-Structures-2021/semester-work-merge-and-insertion-sort/actions/workflows/cmake.yml/badge.svg)](https://github.com/Algorithms-and-Data-Structures-2021/semester-work-merge-and-insertion-sort/actions/workflows/cmake.yml)

Timsort - алгоритм основанный на Merge и Insertion sort, сложность по времени в стандартной реализации O(nlogn), в данной O(nlog^2n), сложность по памяти в стандартной реализации O(n), в данной O(1). Опубликован в 2002 году Тимом Петерсом. Является стандартным алгоритмом сортировки в некоторых популярных языках программирования (Python, Swift и т.д.)

Merge sort - сортировка слиянием. Упорядочивает списки, либо любые другие структуры данных, которые можно получать только последовательно, в нужном порядке. Основана на принципе "разделяй и властвуй". Есть несколько вариантов реализации: top-down и bottom-up. Первый вариант рекурсивно разделяет список на списки состоящие из половин исходного, сортирует их и потом объединяет. Второй вариант сначала разделяет исходный список на списки длины 1, а затем последовательно и упорядочено собирает их в списки с размером в два раза больше.
Сложность по времени в стандартной реализации O(nlogn), в данной O(nlog^2n), сложность по памяти в стандартной реализации O(n), в данной O(1).

## Команда "название команды"

_Заполните таблицу с указанием вклада каждого из участников в проект._

**Примечание**. Преподаватель может определить вклад любого из участников команды по истории коммитов.

| Фамилия Имя   | Вклад (%) | Прозвище              |
| :---          |   ---:    |  ---:                 |
| Давлятов Эмиль   | 100       |  _босс_               |

**Девиз команды**
> _С самого начала у меня была какая-то тактика и я её придерживался._

## Структура проекта

*Проект состоит из следующих частей:

- [`src`](src)/[`include`](include) - реализация структуры данных (исходный код и заголовочные файлы);
- [`benchmark`](benchmark) - контрольные тесты производительности структуры данных (операции добавления, удаления,
  поиска и пр.);
- [`dataset`](dataset)/[`data`](data) - наборы данных для запуска контрольных тестов и их генерация;
- [`dataset`](dataset)/[`out`](out) - результаты бенчмарков

## Требования (Prerequisites)

Рекомендуемые требования:

1. С++ компилятор c поддержкой стандарта C++17 (например, _GNU GCC 8.1.x_ и выше).
2. Система автоматизации сборки _CMake_ (версия _3.12.x_ и выше).
3. Рекомендуемый объем оперативной памяти - не менее 6 ГБ.
4. Свободное дисковое пространство объемом ~ 3 ГБ (набор данных для контрольных тестов).

## Сборка и запуск

### Пример (Windows)

#### Сборка проекта

Склонируйте проект к себе на устройство через [Git for Windows](https://gitforwindows.org/) (либо используйте
возможности IDE):

```shell
git clone https://github.com/Algorithms-and-Data-Structures-2021/semester-work-merge-and-insertion-sort.git
```

Для ручной сборки проекта в терминале введите:

```shell
# переход в папку с проектом
cd C:\Users\username\asd-projects\semester-work-merge-and-insertion-sort

# создание папки для файлов сборки (чтобы не засорять папку с проектом) 
mkdir -p build && cd build 

# сборка проекта
cmake .. -DCMAKE_BUILD_TYPE=RelWithDebInfo && cmake --config RelWithDebInfo --build . 
```

#### Генерация тестовых данных

Тестовые данные хранятся в формате CSV, сгенерировать их вы можете при помощи приложенного в google drive .jar файла, либо же взять уже готовые.

Для генерации данных при помощи jar файла вы должны скачать файл из папки [google drive](https://drive.google.com/drive/folders/1jtFTDrXv-NbN99Ckw8ZSXjIV17Jw3oIt?usp=sharing)
![изображение](https://user-images.githubusercontent.com/79557554/116746776-af726400-aa05-11eb-990e-44ab2334d060.png)


После двойного клика по загруженному файлу, откроется следующее окно, куда вы должны будете ввести путь до папки, где собираетесь хранить тестовые данные^
![изображение](https://user-images.githubusercontent.com/79557554/116747057-0b3ced00-aa06-11eb-8784-d7e5cb271985.png)


После нажатия на кнопку Generate! и пятисекундного ожидания в указанной вами папки появятся сгенерированные случайно значения.


Генерация тестового набора данных в
формате [comma-seperated values (CSV)](https://en.wikipedia.org/wiki/Comma-separated_values):

[Папка с тестовыми данными и файлом java](https://drive.google.com/drive/folders/1jtFTDrXv-NbN99Ckw8ZSXjIV17Jw3oIt?usp=sharing)

#### Контрольные тесты (benchmarks)


Для запуска контрольных тестов необходимо предварительно сгенерировать или скачать готовый набор тестовых данных.

##### Список контрольных тестов

| Название                  | Описание                                | Метрики         |
| :---                      | ---                                     | :---            |
| `merge_sort_benchmark`           | тестирование временной сложности Merge sort | _время_         |
| `timsort_benchmark`           | тестирование временной сложности Timsort    | _время_         |

##### Примеры запуска

Генерируете набор тестовых данных, либо скачиваете с google drive. Процесс генерации описан выше.

Помещаете его по пути dataset\data
![изображение](https://user-images.githubusercontent.com/79557554/119262762-176f3100-bbe5-11eb-9f40-b753bfb6eb7d.png)


Открываете .cpp файл нужного бенчмарка двойным нажатием на него
![изображение](https://user-images.githubusercontent.com/79557554/119262722-e858bf80-bbe4-11eb-8a0c-86c79889d7ab.png)

Запускаете метод main\
![изображение](https://user-images.githubusercontent.com/79557554/119262779-29e96a80-bbe5-11eb-8c09-427cfc0b9fad.png)

Результаты будут сохранены в отдельный csv файл по пути dataset\data для merge sort в файле merge\res.csv, для timsort - tim\res.csv


## Источники

_Список использованных при реализации алгоритма источников._\
[Merge sort on wiki](https://en.wikipedia.org/wiki/Merge_sort#Use_with_tape_drives)\
[Merge sort on GFG](https://www.geeksforgeeks.org/merge-sort/)\
[Timsort on GFG](https://www.geeksforgeeks.org/timsort/)\
[Timsort on wiki](https://ru.wikipedia.org/wiki/Timsort)\
[Timsort on habr](https://habr.com/ru/company/infopulse/blog/133303/)


