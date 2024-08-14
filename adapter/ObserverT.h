
//classic implementation 
#include <iostream>
#include <vector>
#include <set>
#include <functional> // for std::function

namespace ptn::adapter
{
    class Person
    {
    public:
        enum StateChange
        {
            fornameChange,
            surnameChange,
            addressChange
        };

        using PersonObserverT = ObserverT<Person, StateChange>;

        explicit Person(std::string forename, std::string surname)
            : forename_(forename),
              surname_(surname)
        {
        }

        bool attach(std::shared_ptr<PersonObserver> observer)
        {
            auto [pos, res] = observers_.insert(observer);
            return res;
        }

        bool detach(std::shared_ptr<PersonObserver> observer)
        {
        }

        bool attach(std::shared_ptr<PersonObserverT> observer)
        {
            auto [pos, res] = observersT_.insert(observer);
            return res;
        }

        bool detach(std::shared_ptr<PersonObserverT> observer)
        {
        }

        void notify(StateChange state)
        {
            for (auto iter = std::begin(observers_); iter != std::end(observers_);)
            {
                auto const pos = iter++;
                (*pos)->update(*this, state);
            }
        }

        void changeName(std::string newName)
        {
            surname_ = newName;
            notify(StateChange::surnameChange);
        }

    private:
        std::string forename_;
        std::string surname_;

        std::set<std::shared_ptr<PersonObserverT>> observersT_;
    };

    template <typename Subject, typename StateTag>
    class ObserverT
    {
    public:
        using OnUpdate = std::function<void<Subject const &, StateTag>>; // for callback function when subject is trigger

        explicit ObserverT(OnUpdate onUpdate)
            : onUpdate_(std::move(onUpdate))
        {
        }

        void update(Subject const &subject, StateTag tag)
        {
            onUpdate_(subject, tag);
        }

    private:
        OnUpdate onUpdate_;
    };

    void propertyChanged(Person const &person, Person::StateChange property)
    {
        if (property == Person::StateChange::fornameChange || property == Person::StateChange::surnameChange)
        {
            // do something
        }
    }

    void test()
    {

        // create observer
        using PersonObserver = ObserverT<Person, Person::StateChange>;
        PersonObserver nameObserver(propertyChanged);
        PersonObserver addressObserver([](Person const &person, Person::StateChange state)
                                       { std::cout << "Change address " << std::endl; });

        // create subject to observe
        Person person1("A", "B");

        std::shared_ptr<PersonObserver> observerShPtr = std::make_shared<PersonObserver>(nameObserver);
        person1.attach(observerShPtr);

        // here to do something
    }

}

