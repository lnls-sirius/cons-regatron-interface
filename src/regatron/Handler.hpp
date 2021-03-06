#pragma once

#include "log/Logger.hpp"
#include "net/Handler.hpp"

#include "regatron/Comm.hpp"
#include "regatron/Match.hpp"
#include "regatron/Regatron.hpp"

#include <array>
#include <chrono>
#include <iostream>
#include <optional>
#include <string>

namespace Regatron {
constexpr const char* NACK = "NACK";
constexpr const char* ACK = "ACK";

class Handler : public Net::Handler {
  public:
    Handler(std::shared_ptr<Regatron::Comm> regatronComm);
    ~Handler() = default;

  private:
    std::shared_ptr<Regatron::Comm> m_RegatronComm;
    std::vector<Match>              m_Matchers;
    std::string                     handle(const std::string &message) override;
};
} // namespace Regatron
