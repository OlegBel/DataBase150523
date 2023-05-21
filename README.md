# DataBase150523

Программа будет считывать, обрабатывать и сохранять данные, используя только файлы и структуры.
Проект будет реализован в Visual Studio 2019

Что программа должна делать?
Открывать текстовый файл (в нашем случае Input.txt) и читать, изменять, удалять данные в нем.
Какие там данные?
Кол-во элементов в файле, например 3, значит у нас данные на 3-х человек. 
В эти данные входят: фамилия, номер телефона, город.

Действия:
При включении программы (F5) выводится меню, где есть выбор действий.
(1) "Ввод вручную или из файла?" вводим число 1 если пишем вручную, или любое другое число если данные будут загружаться из файла. В нашем случае это файл Input.txt
Если данные считаны, то нас перебрасывает назад в меню, и выбираем число (2) вывод в консоль.
Если все работает, на экран выводятся данные из файла Input.txt 
(3) Изменить данные. Далее, нас спрашивают какой элемент нужно изменить. И потом меняем фамилию, телефон и город.
(4) Удаление данных. Выбираем элемент который хотим удалить.
(5) Добавление данных. Заполняем фамилию, телефон и город.
(6) Сохранение данных. Пишем название файла куда сохраним данные, в нашем случае это файл Out.txt
