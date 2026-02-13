*This project has been created as part of the 42 curriculum by mtaheri, ybarut.*

# push_swap

## Description

`push_swap` is a 42 sorting project where a list of integers must be sorted using
two stacks (`a` and `b`) and a limited set of stack operations.

Goal:
- Output a valid sequence of operations that sorts stack `a` in ascending order.
- Keep the number of operations as low as possible.

This implementation includes:
- Forced strategy modes (`--simple`, `--medium`, `--complex`) and adaptive mode (`--adaptive`, default).
- Adaptive selection based on inversion-ratio disorder, with size-aware routing.
- Optional benchmark reporting via `--bench`.

## Instructions

Compilation:
- Build `push_swap`: `make`
- Build `checker` bonus: `make bonus`
- Rebuild from scratch: `make re`
- Remove objects: `make clean`
- Remove objects and binaries: `make fclean`

Execution:
- Basic usage: `./push_swap 3 2 1`
- With a forced strategy: `./push_swap --complex 3 2 1 6 5 4`
- With adaptive mode explicitly: `./push_swap --adaptive 3 2 1 6 5 4`
- With benchmark output: `./push_swap --bench 3 2 1 6 5 4`
- Options can be combined: `./push_swap --adaptive --bench 3 2 1 6 5 4`

Checker (bonus) example:
- `ARGS="3 2 1 6 5 4"; ./push_swap $ARGS | ./checker $ARGS`

## Strategy selectors

The binary accepts one strategy selector (or none):

- `--simple`: Forces **Simple algorithm (O(n²))** -> **Simple min/max extraction method** (selection-style).
- `--medium`: Forces **Medium algorithm (O(n√n))** -> **Chunk/range-based sorting adaptation**.
- `--complex`: Forces **Complex algorithm (O(n log n))** -> **Radix sort adaptation (LSD)**.
- `--adaptive`: Forces adaptive selection based on measured disorder.

`--adaptive` is the default behavior if no selector is given.

### Benchmark mode

Use `--bench` to print post-sort benchmark data to `stderr`:

- Disorder percentage (two decimals).
- Requested strategy label (`adaptive` if requested) and effective theoretical complexity class.
- Total operation count.
- Per-operation counts for `sa sb ss pa pb ra rb rr rra rrb rrr`.

## Adaptive strategy design

Disorder is measured as the inversion ratio:

- `disorder = inversions / total_pairs`
- `total_pairs = n(n - 1) / 2`

This gives a normalized score in `[0, 1]`, where `0` is already sorted and values near `1` are highly disordered.

Thresholds:

- **Tiny input** (`n <= 5`) -> selects `STRAT_SIMPLE`.
- **Low disorder** (`disorder < 0.2`) -> selects `STRAT_SIMPLE`.
- **Medium disorder** (`0.2 <= disorder < 0.5`) -> selects `STRAT_MEDIUM`.
- **High disorder** (`disorder >= 0.5`) -> selects `STRAT_MEDIUM` for `n <= 600`, otherwise `STRAT_COMPLEX`.

Current internal techniques and complexity arguments (Push_swap model):

- **Low / `STRAT_SIMPLE` -> Simple algorithm (O(n²))**:
  Chosen method: **Simple min/max extraction method** (selection-style repeated minimum extraction).
  Time upper bound: **O(n²)** operations.
  Extra space upper bound: **O(1)** auxiliary (excluding stack nodes already present).
- **Medium / `STRAT_MEDIUM` -> Medium algorithm (O(n√n))**:
  Chosen method: **Chunk/range-based sorting adaptation** on normalized indices.
  A moving index window of size about √n is used: values in the active range are
  pushed from `a` to `b` (with directional placement in `b`), then the stack is
  rebuilt by repeatedly returning the current maximum from `b` to `a`.
  Time upper bound target: **O(n√n)** in this project model.
  Extra space upper bound: **O(1)** auxiliary.
- **High / `STRAT_COMPLEX` -> Complex algorithm (O(n log n))**:
  Chosen method: **Radix sort adaptation (LSD)** on normalized indices.
  For each bit, values with bit `0`
  are pushed to `b` and values with bit `1` are rotated in `a`, then `b` is merged
  back into `a`.
  Time upper bound: **O(n log n)** push_swap operations.
  Extra space upper bound: **O(1)** auxiliary.

## Who Did What

- [ybarut](https://github.com/Restilov) Set up initial project skeleton (core files, headers, and base flow).
- [ybarut](https://github.com/Restilov) Implement linked-list foundation and argument ingestion.
- [mtaheri](https://github.com/2mdtln) Build/cleanup utility layer (libft, norm refactors).
- [mtaheri](https://github.com/2mdtln) Implement integer parsing (`parse_int`).
- [mtaheri](https://github.com/2mdtln) Implement and modularize stack operations (`operations_utils`, `operations_1..3`).
- [mtaheri](https://github.com/2mdtln) Start writing README.
- [ybarut](https://github.com/Restilov) Implement CLI flag parsing (strategy selectors and `--bench`).
- [ybarut](https://github.com/Restilov) Integrate disorder metric computation into the main flow.
- [mtaheri](https://github.com/2mdtln) Implemented `strat_simple` (selection-style, **O(n²)**), used in the low-disorder regime.
- [mtaheri](https://github.com/2mdtln) Implement adaptive strategy selection (`resolve_strategy`) using disorder thresholds.
- [mtaheri](https://github.com/2mdtln) Implemented benchmark reporting for `--bench` (disorder, strategy/complexity, total ops, per-op counts to `stderr`).
- [ybarut](https://github.com/Restilov) Implemented the √n-chunk medium strategy (`STRAT_MEDIUM`) and integrated it into the strategy selector.
- [ybarut](https://github.com/Restilov) Implemented `STRAT_COMPLEX` (radix/LSD based complex strategy).
- [mtaheri](https://github.com/2mdtln) Refactored `STRAT_MEDIUM` to a chunk/range-based strategy and modularized medium helpers.

## Resources
- [gibbontech's push_swap notes](https://www.gibbontech.com/ecole42/push_swap/index.html)
- [sortvisualizer.com](https://www.sortvisualizer.com/)
- [Binary Search Algorithm in 100 Seconds - Fireship](https://www.youtube.com/watch?v=MFhxShGxHWc)
- [Selection Sort - geeksforgeeks](https://www.geeksforgeeks.org/dsa/selection-sort-algorithm-2/)
- [Enumeration (or enum) in C - geeksforgeeks](https://www.geeksforgeeks.org/c/enumeration-enum-c/)
- [Bitwise Operators and WHY we use them - Alex Hyett](https://www.youtube.com/watch?v=igIjGxF2J-w)
- [Radix Sort Algorithm Introduction in 5 Minutes - CS Dojo](https://www.youtube.com/watch?v=XiuSW_mEn7g)
