#ifndef BROKER_HPP
#define BROKER_HPP

#include "actor-zeta/actor/local_actor.hpp"
#include "multiplexer.hpp"
#include "actor-zeta/connection_handler.hpp"

namespace actor_zeta {
    namespace network {
        class broker : public actor_zeta::local_actor {
        public:
            broker(const std::string &);

            broker(const std::string &, std::function<behavior (local_actor*)>);

            multiplexer &backend();

            void set_backend(multiplexer *ptr);

            virtual ~broker() = default;

        private:
            std::unique_ptr<multiplexer> backend_;
            std::map<std::string, write_handler> actions;
            std::atomic<size_t> default_max_msg_size{16 * 1024 * 1024};
        };
    }
}
#endif //ABSTRACT_BROKER_HPP