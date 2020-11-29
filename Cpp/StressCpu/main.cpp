#include <iostream>
#include <thread>
#include <vector>

inline auto GetUnixTimeMs() -> int64_t {
  return std::chrono::duration_cast<std::chrono::milliseconds>(
             std::chrono::system_clock::now().time_since_epoch())
      .count();
}

void task(const bool *stop, const bool *wait, const uint32_t step_ms) {
  int res = 0;
  while (!*stop) {
    res++;
    if (*wait) {
      std::this_thread::sleep_for(std::chrono::milliseconds(step_ms));
    }
  }
}

auto main(int argc, char *argv[]) -> int {
  int res = EXIT_SUCCESS;
  if (argc == 4) {

    // Parse arguments
    const uint32_t nb_thread = static_cast<uint32_t>(std::stoul(argv[1]));
    const uint32_t timeout_ms = static_cast<uint32_t>(std::stoul(argv[2]));
    const uint32_t step_ms = static_cast<uint32_t>(std::stoul(argv[3]));

    // Launch threads
    int64_t start = GetUnixTimeMs();
    std::vector<std::thread> threads;
    bool stop = false;
    bool wait = false;
    for (uint32_t i = 0; i < nb_thread; i++) {
      threads.emplace_back(std::thread(task, &stop, &wait, step_ms));
    }

    // Hash cpu load (work during step_ms then sleep during step_ms)
    for (uint32_t i = 0; i < timeout_ms / 2U / step_ms; i++) {
      std::this_thread::sleep_for(std::chrono::milliseconds(step_ms));
      wait = true;
      std::this_thread::sleep_for(std::chrono::milliseconds(step_ms / 2));
      wait = false;
      std::this_thread::sleep_for(std::chrono::milliseconds(step_ms / 2));
    }

    // Quit each thread
    stop = true;
    for (auto &thread : threads) {
      thread.join();
    }

    std::cout << "Execution time = " << GetUnixTimeMs() - start << "ms"
              << std::endl;
  } else {
    std::cout << "Usage: ./prog <nb_thread> <timeout_ms> <steps_ms>"
              << std::endl;
    res = EXIT_FAILURE;
  }
  return res;
}
