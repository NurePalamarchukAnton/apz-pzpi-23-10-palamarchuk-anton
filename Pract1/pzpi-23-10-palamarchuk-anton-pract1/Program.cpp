//Запити до ШІ : Створи три приклади коду на C++ для демонстрації патерну проектування State. Кожен приклад повинен показувати різні рівні реалізації:
//1.	Базовий інтерфейс State та Context – тільки визначення класів State та Context без конкретних станів.
//2.	Додавання конкретних станів – реалізація ConcreteStateA та ConcreteStateB з методом handle(), який виводить повідомлення про поведінку стану.
//3.	Повна реалізація з Context – ConcreteStateA та ConcreteStateB, Context з методами setState() та request(), main() демонструє створення контексту, виклики request() і динамічну зміну стану.
//Кожен приклад повинен бути окремим фрагментом коду з коментарями і готовий до компіляції.

#include <iostream>

class State {
public:
    virtual ~State() = default;
    virtual void handle() = 0;
};

class Context {
public:
    virtual ~Context() = default;
    virtual void setState(State* state) = 0;
};

////////////////////////////////////////////////////////
#include <iostream>

class State {
public:
    virtual ~State() = default;
    virtual void handle() = 0;
};

class ConcreteStateA : public State {
public:
    void handle() override {
        std::cout << "Виконуємо поведінку стану A\n";
    }
};

class ConcreteStateB : public State {
public:
    void handle() override {
        std::cout << "Виконуємо поведінку стану B\n";
    }
};

////////////////////////////////////////////////////////
#include <iostream>

class State {
public:
    virtual ~State() = default;
    virtual void handle() = 0;
};

class ConcreteStateA : public State {
public:
    void handle() override {
        std::cout << "Поведінка стану A\n";
    }
};

class ConcreteStateB : public State {
public:
    void handle() override {
        std::cout << "Поведінка стану B\n";
    }
};

class Context {
private:
    State* state;
public:
    Context(State* initialState) : state(initialState) {}

    void setState(State* newState) {
        state = newState;
    }

    void request() {
        state->handle();
    }
};

int main() {
    ConcreteStateA stateA;
    ConcreteStateB stateB;

    Context context(&stateA);
    context.request();

    context.setState(&stateB);
    context.request();

    return 0;
}