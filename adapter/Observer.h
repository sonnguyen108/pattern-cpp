// Observer.h
// use like abstract notification mechanism

// classic implementation
#include <iostream>
#include <vector>
#include <set>

// observer.h
namespace ptn::adapter
{
    template <typename Subject, typename StateTag>
    class Observer
    {
    public:
        virtual ~Observer() = default;
        virtual void update(Subject const &subject, StateTag tag) = 0;
    };

    class Person
    {
    public:
        enum StateChange
        {
            fornameChange,
            surnameChange,
            addressChange
        };

        using PersonObserver = Observer<Person, StateChange>;

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

        std::set<std::shared_ptr<PersonObserver>> observers_;
    };
}

