#pragma once

#include <boost/bimap.hpp>

namespace peak {

/**
 * Implementation of the EventGenerator class.
 *
 * Class that generates events following Gaussian distribution
 * (https://en.wikipedia.org/wiki/Normal_distribution) using
 * boost::normal_distribution with mean = 10 and variance 0.5, with dummy
 * timestamp value for each event that takes current system clock time and adds
 * index of generated event, in that way creating events with unique timestamp.
 * These events are saved in boost::bimap and simple analysis is done on these
 * events. The more events are generated, the more accurate the prediction is
 * that for the Gaussian distribution, the values less than one standard
 * deviation away from the mean account for 68.27% of the generated events,
 * while two standard deviations from the mean account for 95.45% and three
 * standard deviations account for 99.73%.
 *
 */
class EventGenerator {
private:
  using Events = boost::bimap<float, long>;
  using time_stamp = Events::value_type;
  /// events bimap
  Events events;
  /// number of generated events
  int event_number;
  /// mean value used in calculation of Gaussian distribution
  static constexpr float mean = 10.0;
  /// variance value used in calculation of Gaussian distribution
  static constexpr float variance = 0.5;

public:
  /**
   * Constructor of EventGenerator
   *
   * Default implementation
   */
  EventGenerator() = default;

  /**
   * Destructor of EventGenerator
   *
   * Default implementation
   */
  ~EventGenerator() = default;

  /**
   * Number of generated events in bimap.
   *
   * @return number of generated events
   */
  int no_of_generated_events() const { return events.size(); }

  /**
   * Function that generates events following Gaussian distribution as key of
   * bimap and dummy timestamp value for each event as value of boost::bimap.
   *
   * @param no_of_events number of events to be generated
   */
  void generate_events(const int no_of_events);

  /**
   * Function that prints key and value of generated events.
   */
  void print_events() const;

  /**
   * Function that finds the event that is on right most edge of Gaussian
   * distribution.
   *
   * @return position of event created on right most edge of Gaussian
   * distribution
   */
  float right_edge_event() const;

  /**
   * Function that finds the event that is on left most edge of Gaussian
   * distribution.
   *
   * @return position of event created on left most edge of Gaussian
   * distribution
   */
  float left_edge_event() const;

  /**
   * Function that finds the event that is generated first.
   *
   * @return time of event created first
   */
  long first_event() const;

  /**
   * Function that finds the event that is generated last.
   *
   * @return time of event created last
   */
  long last_event() const;

  /**
   * Function that returns % of events generated following Gaussian
   * distribution, that are positioned one sigma away from mean. For the
   * Gaussian distribution, the values less than one standard deviation away
   * from the mean account for 68.27% of the generated events.
   *
   * @return % of the events that are generated in one sigma away from
   * mean
   */
  float no_of_events_in_one_sigma() const;

  /**
   * Function that returns % of events generated following Gaussian
   * distribution, that are positioned two sigma away from mean. For the
   * Gaussian distribution, the values less than two standard deviation away
   * from the mean account for 95.45% of the generated events.
   *
   * @return % of the events that are generated in two sigma away from
   * mean
   */
  float no_of_events_in_two_sigma() const;

  /**
   * Function that returns % of events generated following Gaussian
   * distribution, that are positioned three sigma away from mean. For the
   * Gaussian distribution, the values less than three standard deviation away
   * from the mean account for 99.73% of the generated events.
   *
   * @return % of the events that are generated in three sigma away from
   * mean
   */
  float no_of_events_in_three_sigma() const;
};

} // namespace peak
