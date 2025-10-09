# push_swap

An algorithmic sorting project from Hive Helsinki.  
The goal is to sort data on a stack using a limited set of operations, optimized for minimal moves.

---

## 🧠 Overview

`push_swap` takes a list of integers and outputs the shortest sequence of operations to sort them in ascending order using two stacks (`a` and `b`).

The allowed operations are:
- `sa`, `sb`, `ss` — swap top elements  
- `pa`, `pb` — push top element between stacks  
- `ra`, `rb`, `rr` — rotate stack up  
- `rra`, `rrb`, `rrr` — rotate stack down  

---

## ⚙️ Compilation

```bash
make
