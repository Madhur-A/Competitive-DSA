# Advent of Code 2025 - Scala Solutions

This repository contains my solutions to **Advent of Code 2025**, all implemented in **Scala**.  
A few notes to set expectations and explain some choices:

**Why Scala?**  
- I chose Scala primarily for the ease of input parsing. For me (especially in the context of Advent of Code) parsing the input often takes more effort than solving the actual problem. While this can be done in any language, functional languages like `Scala` (or `Haskell`) make such tasks significantly more pleasant and expressive.
    
**On Scala itself**  
- Despite Scala having its own compiler (`scalac`/`dotc`), it remains deeply tied to the JVM ecosystem, which often makes the experience feel constrained by Java-era tooling. Even so, `Scala` is the language that best aligns with my personal coding style. Among all the languages I’ve worked with, it feels the most amenable to my taste. It’s a bit of a shame that `Scala` lacks a truly cohesive, first-class compiler ecosystem comparable to `Haskell`’s.
    
**Project structure & build** 
- Each day’s solution is structured as a small **sbt** project. Every Advent of Code problem consists of two parts, and both parts are implemented in the same source file as separate methods:
    
    -   `one()` for Part 1
        
    -   `two()` for Part 2
        
    
    A simple `$ sbt run` should suffice to run these examples.
    
**Code quality & style** 
- These solutions are written _for fun_. As a result, strict decorum, optimal readability, or algorithmic optimality are not always guaranteed. Sub-optimal approaches are sometimes used deliberately, especially since there are no time or performance constraints beyond curiosity and enjoyment.
