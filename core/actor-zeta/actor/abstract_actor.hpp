#ifndef ABSTRACT_ACTOR_HPP
#define ABSTRACT_ACTOR_HPP

#include <set>

#include <actor-zeta/channel/abstract_channel.hpp>
#include <actor-zeta/environment/environment.hpp>
#include <actor-zeta/forwards.hpp>

namespace actor_zeta { namespace actor {
///
/// @brief Abstract concept of an actor
///

        class abstract_actor : public ref_counted {
        public:           
            virtual bool send(messaging::message&&) = 0;

            virtual bool send(messaging::message&&, executor::execution_device *) = 0;

            virtual ~abstract_actor();

            actor_address address() const noexcept;

            auto type() const -> abstract;

            auto name() const -> const std::string &;

            auto locating() const -> locations;

            virtual auto message_types() const -> std::set<std::string> ;

        protected:
            auto env() -> environment::environment& ;

            abstract_actor(environment::abstract_environment *, const std::string &);

            metadata type_;

        private:
            abstract_actor() = delete;

            abstract_actor(const abstract_actor &) = delete;

            abstract_actor &operator=(const abstract_actor &) = delete;

            environment::environment env_;
        };
    }
}

#endif //ABSTRACT_ACTOR_HPP