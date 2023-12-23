#include "InputSystem.hpp"

void InputSystem::mapKeyToAction(SDL_KeyCode key, ActionType action) {
  auto it = InputSystem::keyMappings.find(key);

  if (it == InputSystem::keyMappings.end()) {
    InputSystem::keyMappings.emplace(key, action);
    InputSystem::actions.emplace(action, true);
  }
}

void InputSystem::mapMouseToAction(ActionType action) {
  actions[action] = false;
}

bool InputSystem::isActionMapped(ActionType action) const {
  auto it = actions.find(action);

  if (it != actions.end()) {
    return it->second;
  }

  return false;
}

InputSystem::FunCheckMapErr InputSystem::pressKey(SDL_KeyCode key) {
  auto it = keyMappings.find(key);

  if (it != keyMappings.end()) {
    return FunCheckMapErr(it->second);
  }

  else {
    return FunCheckMapErr("Key not mapped");
  }
}