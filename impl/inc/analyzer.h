#pragma once

namespace peak {

/**
 * Analyzer interface class.
 *
 */
class Analyzer {
public:
  /**
   * Constructor of Analyzer
   *
   * Default constructor
   */
  Analyzer() = default;

  /**
   * Destructor of Analyzer
   *
   * Default destructor, virtual due to inheritance.
   */
  virtual ~Analyzer() = default;

  /**
   * Pure virtual analyze_events function
   */
  virtual void analyze_events(const int no_of_events) = 0;

  /**
   * Pure virtual print_events function
   */
  virtual void print_events() const = 0;

private:
  /**
   * Pure virtual right_edge_event function
   */
  virtual float right_edge_event() const = 0;

  /**
   * Pure virtual left_edge_event function
   */
  virtual float left_edge_event() const = 0;

  /**
   * Pure virtual first_time_stamp function
   */
  virtual long first_time_stamp() const = 0;

  /**
   * Pure virtual last_time_stamp function
   */
  virtual long last_time_stamp() const = 0;

  /**
   * Pure virtual one_sigma_from_mean function
   */
  virtual float one_sigma_from_mean() const = 0;

  /**
   * Pure virtual two_sigma_from_mean function
   */
  virtual float two_sigma_from_mean() const = 0;

  /**
   * Pure virtual three_sigma_from_mean function
   */
  virtual float three_sigma_from_mean() const = 0;
};

} // namespace peak
