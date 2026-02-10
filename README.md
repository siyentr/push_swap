*This project has been created as part of the 42 curriculum by mtaheri, ybarut.*

# push_swap

## Strategy selectors

The binary accepts one strategy selector (or none):

- `--simple`: Forces the O(n²) method.
- `--medium`: Forces the O(n√n) method (**TODO**, currently falls back to simple).
- `--complex`: Forces the O(n log n) method (**TODO**, currently falls back to simple).
- `--adaptive`: Forces adaptive selection based on measured disorder.

`--adaptive` is the default behavior if no selector is given.

### Benchmark mode

Use `--bench` to print post-sort benchmark data to `stderr`:

- Disorder percentage (two decimals).
- Effective strategy selected and theoretical complexity class.
- Total operation count.
- Per-operation counts for `sa sb ss pa pb ra rb rr rra rrb rrr`.

## Adaptive strategy design

Disorder is measured as the inversion ratio:

- `disorder = inversions / total_pairs`
- `total_pairs = n(n - 1) / 2`

This gives a normalized score in `[0, 1]`, where `0` is already sorted and values near `1` are highly disordered.

Thresholds:

- **Low disorder** (`disorder < 0.2`) -> selects `STRAT_SIMPLE`.
- **Medium disorder** (`0.2 <= disorder < 0.5`) -> selects `STRAT_MEDIUM`.
- **High disorder** (`disorder >= 0.5`) -> selects `STRAT_COMPLEX`.

Current internal techniques and complexity arguments (Push_swap model):

- **Low / `STRAT_SIMPLE`**:
  Uses repeated minimum extraction with rotations and pushes (selection-style behavior).
  Time upper bound: **O(n²)** operations.
  Extra space upper bound: **O(1)** auxiliary (excluding stack nodes already present).
- **Medium / `STRAT_MEDIUM`**:
  Uses a √n-chunk strategy on normalized indices: the input range is split into roughly √n contiguous chunks in index space, elements are pushed to stack `b` chunk by chunk with directional rotations chosen to minimize distance, then reassembled by repeatedly bringing the maximum index in `b` back to `a`.
  Time upper bound: **O(n√n)** push_swap operations (each element participates in `O(√n)` scans/rotations on average).
  Extra space upper bound: **O(1)** auxiliary.
- **High / `STRAT_COMPLEX`**:
  **TODO** target technique will be chosen to satisfy **O(n log n)** time.

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

## Resources
- [gibbontech's push_swap notes](https://www.gibbontech.com/ecole42/push_swap/index.html)
- [sortvisualizer.com](https://www.sortvisualizer.com/)
- [Binary Search Algorithm in 100 Seconds - Fireship](https://www.youtube.com/watch?v=MFhxShGxHWc)
- [Selection Sort - geeksforgeeks](https://www.geeksforgeeks.org/dsa/selection-sort-algorithm-2/)
- [Enumeration (or enum) in C - geeksforgeeks](https://www.geeksforgeeks.org/c/enumeration-enum-c/)
