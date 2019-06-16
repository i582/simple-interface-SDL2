# simple-interface-SDL2
Just simple interface with SDL2 and C++17

>***Главное, помните, это не пользовательский интерфейс для всех, а лишь возможная реализация для программистов нашей группы для курсовой работы, то есть здесь не ставится вопрос удобности для конечного пользователя, ввиду отсутсвия смысла в данной работе***

Итак, это простой интерфейс для нашей курсовой работы.

Начнем с того, что сам интерфейс настраивается в файле `Interface_Setup.cpp`

Какие элементы можно добавить:

## 1.  Надпись (`Label`) 

Для ее добавления синтаксис такой
```cpp
Label* _имя_ = new Label(
  _координаты_в_SDL_Rect_, 
  _надпись_, 
  _путь_к_шрифту_, 
  _размер_шрифта_, 
  _тип_выравнивание(LEFT_ALIGN or CENTERED_ALIGN)
);
  
Labels.push_back(_имя_);
```

После объявления, но до добавления ее в общий список Надписей, можно:
1. Заблокировать `_имя_->Block(true)` и соотвественно разблокировать, а так же получить текущее значение
2. Отобразить `_имя_->Display(true)` и соотвественно скрыть, а так же получить текущее значение

## 2. Кнопка (`Button`)

Для ее добавления синтаксис такой
```cpp
Button* _имя_ = new Button(
  _координаты_в_SDL_Rect_,
  _надпись_,
  _тип_кнопки_что_она_будет_делать,
  _путь_к_шрифту_, 
  _размер_шрифта_,
  _тип_выравнивание(LEFT_ALIGN or CENTERED_ALIGN)
);

Buttons.push_back(_имя_);
```

После объявления, но до добавления ее в общий список Кнопок, можно:
1. Заблокировать `_имя_->Block(true)` и соотвественно разблокировать, а так же получить текущее значение
2. Отобразить `_имя_->Display(true)` и соотвественно скрыть, а так же получить текущее значение

## 3. Поле ввода (`Input`)

Для его добавления синтаксис такой
```cpp
Input* _имя_ = new Input(
  _координаты_в_SDL_Rect_,
  _путь_к_шрифту_, 
  _размер_шрифта_,
  _тип_выравнивание(LEFT_ALIGN or CENTERED_ALIGN)
);

Inputs.push_back(_имя_);
```

После объявления, но до добавления его в общий список Полей ввода, можно:
1. Заблокировать `_имя_->Block(true)` и соотвественно разблокировать, а так же получить текущее значение
2. Отобразить `_имя_->Display(true)` и соотвественно скрыть, а так же получить текущее значение

## 4. Поле вывода (`TextField`)

Для его добавления синтаксис такой
```cpp
TextField* _имя_ = new TextField(
  _координаты_в_SDL_Rect_,
  _путь_к_шрифту_, 
  _размер_шрифта_,
  _тип_выравнивание(LEFT_ALIGN or CENTERED_ALIGN)
);

TextFields.push_back(_имя_);
```

После объявления, но до добавления его в общий список Полей вывода, можно:
1. Заблокировать `_имя_->Block(true)` и соотвественно разблокировать, а так же получить текущее значение
2. Отобразить `_имя_->Display(true)` и соотвественно скрыть, а так же получить текущее значение


## 5. Выпадающий список (listItem)

Для его добавления синтаксис такой
```cpp

ItemList* _имя_ = new ItemList(
  _координаты_в_SDL_Rect_,
  _размеры_элемента_списка_в_SDL_Rect_,
  _путь_к_шрифту_, 
  _размер_шрифта_,
  _тип_выравнивание(LEFT_ALIGN or CENTERED_ALIGN)
);

ItemLists.push_back(_имя_);

```

После объявления, но до добавления его в общий список Выпадающих полей, можно:
1. Заблокировать `_имя_->Block(true)` и соотвественно разблокировать, а так же получить текущее значение
2. Отобразить `_имя_->Display(true)` и соотвественно скрыть, а так же получить текущее значение
3. **Добавить элемент `_имя_->add(_текст_, _флаг_по_котороу_определяется_что_это_такое);`**

## 6. Выпадающий список со значением в теле (DropDownList)

Для его добавления синтаксис такой
```cpp

DropDownList* _имя_ = new DropDownList(
  _координаты_в_SDL_Rect_,
  _размеры_элемента_списка_в_SDL_Rect_,
  _тип_выпадающего_списка_(LEFT_SIDE or DOWN_SIDE),
  _путь_к_шрифту_, 
  _размер_шрифта_,
  _тип_выравнивание(LEFT_ALIGN or CENTERED_ALIGN)
);

DropDownLists.push_back(_имя_);

```

После объявления, но до добавления его в общий список Выпадающих полей, можно:
1. Заблокировать `_имя_->Block(true)` и соотвественно разблокировать, а так же получить текущее значение
2. Отобразить `_имя_->Display(true)` и соотвественно скрыть, а так же получить текущее значение
3. **Добавить элемент `_имя_->add(_текст_, _флаг_по_котороу_определяется_что_это_такое);`**



# Настройка событий для новых элементов

После того, как вы добавлили новый элемент, вы должны связать эти элементы с каким-то действием.

## Кнопка и input

На стадии добавления кнопки, вы указываете тип этой кнопки, то есть что она будет делать, допустим, вы хотите  сделать, чтобы эта кнопка была завершающей в какой-либо части вашего интерфейса, и по клику по ней, вы получали значение из `input`. Рекомендуется, когда вы добавляете кнопку, добавить в файл `interface.h` в `enum BUTTON_TYPES` тип вашей кнопки (например, `BUTTON_OK_SET_VALUE`), которое будет хранить фактическое расположение в массиве кнопок и по которому оно будет в дальнейшем использоваться. После того, как ваша кнопка добавлена и настроена, вы должны перейти в файл `Interface_OnEvent_Function.cpp` и в функции `mouseButtonDown` в цикле перебирающем все кнопки в `switch` добавить ваш флаг в качестве нового `case`, а внутри прописать необходимые для вас действия. Опять же допустим мы хотим получить значение из `input`. Для начала настроим сам `input`. На стадии его добавления, мы прописываем тип, как и кнопки, мы должны добавить новое значение, но теперь в `enum INPUT_TYPES`. После чего этот `input` будет доступен по `Items->at(_ЗНАЧЕНИЕ_КОТОРОЕ_ВЫ_ДОБАВИЛИ_) `. После этого, чтобы получить значение из данного `input`, вы должны прописать в ранее описанном `case` в файле `Interface_OnEvent_Function.cpp` в функции `mouseButtonDown` в цикле перебирающем все кнопки в `switch` следующее:

```cpp
string text = Inputs->at(_ЗНАЧЕНИЕ_КОТОРОЕ_ВЫ_ДОБАВИЛИ_ДЛЯ_INPUT)->getValue();
```

таким образом в переменной `text` будет значение из `input`.

После этого, допустим, вы захотите заблокировать это `input`, тогда сразу после строк выше, добавьте 
```cpp
Inputs->at(_ЗНАЧЕНИЕ_КОТОРОЕ_ВЫ_ДОБАВИЛИ_ДЛЯ_INPUT_)->Block(true);
Inputs->at(_ЗНАЧЕНИЕ_КОТОРОЕ_ВЫ_ДОБАВИЛИ_ДЛЯ_INPUT_)->render();
```
***! Важно, после того, как вы как-либо изменили элемент, нужно вызвать у него метод `render`***

А для сокрытия элемента, вызовите метод Display(false) и не забудьте вызвать метод `render`

## Выпадающие списки

Работа со списками похожа на работу с кнопками, с тем различием, что мы добавляем типы для каждого элемента. И каждый такой элемент опять же должен иметь свой идентификатор, но уже в `enum ITEM_LIST_TYPES` для `itemList` и `enum DROP_ITEM_LIST_TYPES` для `DropDownList` (перечисления должны иметь нулевой элемент, нулевой элемент не должен быть функциональным).

После добавления элементов в список, для настройки `itemList` перейдите в файл  `Interface_OnEvent_Function.cpp` в функции `mouseButtonUp` в цикле перебирающем все `itemList` в `switch` по переменной `flag` добавьте новые `case`, как и при работе с кнопками. Именем для `case` будет добавленные вами идентификаторы в  `enum ITEM_LIST_TYPES`. Допустим у вас есть `itemList` с следующими полями:
1. Показать `input`
2. Скрыть `input`

И уже настроенный `input` с предыдущего примера. Тогда, допустим, у 1 элемента списка будет название `SHOW_INPUT`, а у 2 — `HIDE_INPUT`. Добавим их в `enum ITEM_LIST_TYPES`. Теперь перейдем в файл  `Interface_OnEvent_Function.cpp` в функции `mouseButtonUp` в цикле перебирающем все `itemList` в `switch` по переменной `flag` добавляем `case` с `SHOW_INPUT` и `case` с `HIDE_INPUT`. 

Пропишем следующие:
```cpp
case SHOW_INPUT{
  if(!Inputs->at(_ЗНАЧЕНИЕ_КОТОРОЕ_ВЫ_ДОБАВИЛИ_ДЛЯ_INPUT_)->Show()){
    Inputs->at(_ЗНАЧЕНИЕ_КОТОРОЕ_ВЫ_ДОБАВИЛИ_ДЛЯ_INPUT_)->Show(true);
    Inputs->at(_ЗНАЧЕНИЕ_КОТОРОЕ_ВЫ_ДОБАВИЛИ_ДЛЯ_INPUT_)->render();
  }
  break;
}

case HIDE_INPUT{
  if(Inputs->at(_ЗНАЧЕНИЕ_КОТОРОЕ_ВЫ_ДОБАВИЛИ_ДЛЯ_INPUT_)->Show()){
    Inputs->at(_ЗНАЧЕНИЕ_КОТОРОЕ_ВЫ_ДОБАВИЛИ_ДЛЯ_INPUT_)->Show(false);
    Inputs->at(_ЗНАЧЕНИЕ_КОТОРОЕ_ВЫ_ДОБАВИЛИ_ДЛЯ_INPUT_)->render();
  }
  break;
}
```

И теперь, если мы будем выбирать какой-либо пункт, то будет выполняться требуемое действие.

Работа с `DropDownList` проще, при выборе нужного нам пункта, значение помещается в внутреннюю переменную этого списка и чтобы ее получить нужно вызвать метод `getValue()` у нужного вам списка (который вы добавили в `enum DROP_ITEM_LIST_TYPES`), так
```cpp
string value = DropDownLists->at(_ЗНАЧЕНИЕ_КОТОРОЕ_ВЫ_ДОБАВИЛИ_)->getValue();
```

## Поле вывода

Как и с предыдущими элементами, при добавлении поля ввода, вы должны задать для него идентификатор в `enum TEXT_FIELD_TYPES`, для дальнейшего использования. Тогда обращение к нужному будет выглядеть так:
```cpp
TextFields->at(_ЗНАЧЕНИЕ_КОТОРОЕ_ВЫ_ДОБАВИЛИ_)
```

Для добавления, как было сказано ранее используется метод `add`, принимающий `string`
```cpp
TextFields->at(_ЗНАЧЕНИЕ_КОТОРОЕ_ВЫ_ДОБАВИЛИ_)->add("new line")
```
