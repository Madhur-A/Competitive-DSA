# Rust Coding Conventions

This document defines the coding conventions adopted for this project. The goal is to improve readability, consistency, and maintainability across the codebase. The style is highly personal and may not fully adhere to general Rust conventions.

---

## 1. Usage of `return`

The use of the `return` keyword is **explicitly preferred** in imperative-style code.

- Use `return` to clearly indicate execution flow and exit points within functions.
- Explicit `return` statements improve readability, especially in:
  - Functions with multiple exit paths
  - Error handling branches
  - Early exits for validation or guard conditions

**Rationale:**
Being explicit about control flow reduces ambiguity and makes the intent of the code easier to understand.

---

## 2. Functional Style and `return`

In functional programming style, the `return` keyword is generally **not used**.

- Prefer expression-based returns in:
  - Closures
  - Iterator chains
  - Expression-oriented functions
- The final expression in a block implicitly determines the return value.

**Rationale:**
Omitting `return` in functional contexts preserves idiomatic Rust style and improves composability.

---

## 3. Usage of `rustfmt`

Formatted using `rustfmt`.

- Existing code may be:
  - Fully formatted by `rustfmt`, or
  - Slightly adjusted afterward to improve readability.

**Rationale:**
Consistent formatting improves readability and aligns the project with community-standard Rust practices.

---

## 4. Declaration of Variables

- Prefer **type inference** with constructor calls instead of explicit type annotations when the type can be clearly inferred.
- This style is conducive to functional style and it also improves readability, by avoiding redundancy while keeping the type clear from context.

**Preferred Style:**

```rust
let g = HashMap::<usize, i32>::new();
```
**Avoid:**

```rust
let g: HashMap<usize, i32> = HashMap::new();
```
**Rationale:**
Using type inference reduces boilerplate and emphasizes the constructor rather than repeating the type unnecessarily, while still keeping the code readable and explicit.
