#pragma once

#include "analyzer.h"
#include "event_generator.h"

namespace peak {

/**
 * Implementation of the PeakAnalyzer class.
 *
 * Class PeakAnalyzer publicly inherits Analyzer.
 *
 */
class PeakAnalyzer : public Analyzer {
private:
  /// EventGenerator obj
  EventGenerator event_generator;

public:
  /**
   * Constructor of PeakAnalyzer
   *
   * Instantiation of EventGenerator class too
   */
  PeakAnalyzer();

  /**
   * Destructor of PeakAnalyzer
   *
   * Default implementation
   */
  ~PeakAnalyzer() = default;

  /**
   * Implementation of analyze_events function, that calls for
   * generate_events on event_generator.
   *
   * @param no_of_events number of events to be generated
   */
  void analyze_events(const int no_of_events) override;

  /**
   * Implementation of print_events function, that calls for
   * print_events on event_generator.
   */
  void print_events() const override;

  /**
   * Implementation of right_edge_event function, that calls for
   * right_edge_event on event_generator.
   *
   * @return position of event created on right most edge of Gaussian
   * distribution
   */
  float right_edge_event() const override;

  /**
   * Implementation of left_edge_event function, that calls for
   * left_edge_event on event_generator.
   *
   * @return position of event created on left most edge of Gaussian
   * distribution
   */
  float left_edge_event() const override;

  /**
   * Implementation of first_time_stamp function, that calls for
   * first_event on event_generator.
   *
   * @return time of event created first
   */
  long first_time_stamp() const override;

  /**
   * Implementation of last_time_stamp function, that calls for
   * last_time_stamp_event on event_generator.
   *
   * @return time of event created last
   */
  long last_time_stamp() const override;

  /**
   * Implementation of one_sigma_from_mean function, that calls for
   * no_of_events_in_one_sigma on event_generator.
   *
   * @return percantage of the events that are generated in one sigma away from
   * mean
   */
  float one_sigma_from_mean() const override;

  /**
   * Implementation of two_sigma_from_mean function, that calls for
   * no_of_events_in_two_sigma on event_generator.
   *
   * @return percantage of the events that are generated in two sigma away from
   * mean
   */
  float two_sigma_from_mean() const override;

  /**
   * Implementation of three_sigma_from_mean function, that calls for
   * no_of_events_in_three_sigma on event_generator.
   *
   * @return percantage of the events that are generated in three sigma away
   * from mean
   */
  float three_sigma_from_mean() const override;
};

} // namespace peak
