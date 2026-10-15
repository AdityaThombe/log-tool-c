# log-tool-c

Small log helpers in C with a CMake + CTest suite. **Demo target for ProofPatch: intentionally contains several security bugs** (buffer overflows, command injection). Never deploy this code.

Run the tests: `cmake -S . -B build && cmake --build build && ctest --test-dir build`.
