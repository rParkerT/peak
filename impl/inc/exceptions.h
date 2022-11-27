#pragma once

#include <iostream>
#include <string>

/**
 * Implementation of the NoGeneratedEventsException class. It is thrown during
 * call of EventGenerator class methods, when the number of generated events is
 * 0.
 *
 * Class NoGeneratedEventsException is exception class.
 *
 */
class NoGeneratedEventsException : public std::exception {
public:
  /**
   * Constructor of NoGeneratedEventsException
   *
   * Default implementation
   */
  NoGeneratedEventsException() noexcept = default;

  /**
   * Destructor of NoGeneratedEventsException
   *
   * Default implementation
   */
  ~NoGeneratedEventsException() = default;

  /**
   * Implementation of what function
   *
   * In case the exception is thrown during call of EventGenerator class
   * methods, when the number of generated events is 0, the string "No generated
   * events." will be displayed
   */
  virtual const char *what() const throw() { return "No generated events."; }
};
