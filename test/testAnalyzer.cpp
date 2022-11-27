#define CATCH_CONFIG_ENABLE_BENCHMARKING
#include "analyzer.h"
#include "event_generator.h"
#include "peak_analyzer.h"
#include <catch.hpp>

TEST_CASE("Analyzer - Check if output is printed for 100 generated events") {
  peak::Analyzer *analyzer = new peak::PeakAnalyzer();
  analyzer->analyze_events(100);
  delete analyzer;
}

TEST_CASE("Analyzer - Check if output is printed for 10.000 generated events") {
  peak::Analyzer *analyzer = new peak::PeakAnalyzer();
  analyzer->analyze_events(10000);
  delete analyzer;
}

TEST_CASE("EventGenerator - Create 1000 events, call EventGenerator functions "
          "and check return values") {
  peak::EventGenerator event_generator{};
  float mean = 10.0;
  float variance = 0.5;
  event_generator.generate_events(1000);
  REQUIRE(event_generator.no_of_generated_events() == 1000);
  REQUIRE(event_generator.right_edge_event() <= (mean + 4 * variance));
  REQUIRE(event_generator.left_edge_event() >= (mean - 4 * variance));
  auto now = std::chrono::system_clock::now();
  auto duration = now.time_since_epoch();
  auto millis =
      std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
  REQUIRE(event_generator.first_event() < millis);
  REQUIRE(event_generator.last_event() < millis + 1000);
  REQUIRE(event_generator.no_of_events_in_one_sigma() <= (68.2 + (68.2 * 0.1)));
  REQUIRE(event_generator.no_of_events_in_two_sigma() <=
          (95.4 + (95.4 * 0.05)));
  REQUIRE(event_generator.no_of_events_in_three_sigma() <=
          (99.6 + (99.6 * 0.01)));
}

TEST_CASE("Benchmark - generate events") {
  BENCHMARK("Insert 100 events in bimap") {
    peak::EventGenerator event_generator{};
    event_generator.generate_events(100);
  };

  BENCHMARK("Insert 1000 events in bimap") {
    peak::EventGenerator event_generator{};
    event_generator.generate_events(1000);
  };
}

TEST_CASE("Benchmark - find right edge event from 100 generated events") {
  peak::EventGenerator event_generator{};
  event_generator.generate_events(100);
  BENCHMARK("Find right edge event from 100 events") {
    event_generator.right_edge_event();
  };
}

TEST_CASE("Benchmark - find right edge event from 1000 generated events") {
  peak::EventGenerator event_generator{};
  event_generator.generate_events(1000);
  BENCHMARK("Find right edge event from 1000 events") {
    event_generator.right_edge_event();
  };
}

TEST_CASE("Benchmark - find first event from 100 generated events") {
  peak::EventGenerator event_generator{};
  event_generator.generate_events(100);
  BENCHMARK("Find first event from 100 events") {
    event_generator.first_event();
  };
}

TEST_CASE("Benchmark - find first event from 1000 generated events") {
  peak::EventGenerator event_generator{};
  event_generator.generate_events(1000);
  BENCHMARK("Find first event from 1000 events") {
    event_generator.first_event();
  };
}

TEST_CASE("Benchmark - find number of events in one sigma from 100 generated "
          "events") {
  peak::EventGenerator event_generator{};
  event_generator.generate_events(100);
  BENCHMARK("Find number of events in one sigma from 100 events") {
    event_generator.no_of_events_in_one_sigma();
  };
}

TEST_CASE("Benchmark - find number of events in one sigma from 1000 generated "
          "events") {
  peak::EventGenerator event_generator{};
  event_generator.generate_events(1000);
  BENCHMARK("Find number of events in one sigma from 1000 events") {
    event_generator.no_of_events_in_one_sigma();
  };
}
