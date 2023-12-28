/*
 * All or portions of this file Copyright (c) Amazon.com, Inc. or its affiliates
 * or its licensors.
 *
 * For complete copyright and license terms please see the LICENSE at the root
 * of this distribution (the "License"). All use of this software is governed by
 * the License, or, if provided, by the license below or the license
 * accompanying this file. Do not remove or modify any license notices. This
 * file is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF
 * ANY KIND, either express or implied.
 *
 */

#pragma once

#include <aws/gamelift/common/Outcome.h>
#include <aws/gamelift/internal/model/Message.h>
#include <aws/gamelift/internal/network/IGameLiftMessageHandler.h>

namespace Aws {
namespace GameLift {
namespace Internal {

/**
 * Class representing a default callback for CreateGameSession (action)
 */
class CreateGameSessionCallback {
public:
  // Constructors
  CreateGameSessionCallback(IGameLiftMessageHandler *gameLiftMessageHandler)
      : m_gameLiftMessageHandler(gameLiftMessageHandler){};

  ~CreateGameSessionCallback() = default;

  // Methods

  /**
   * Callback to trigger on websocket "CreateGameSession" action
   * @param data
   * @return
   */
  GenericOutcome OnStartGameSession(const std::string &data);

  // Constants
  static constexpr const char *CREATE_GAME_SESSION = "CreateGameSession";

private:
  IGameLiftMessageHandler *m_gameLiftMessageHandler;
};
} // namespace Internal
} // namespace GameLift
} // namespace Aws
