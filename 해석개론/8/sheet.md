Here is a comprehensive, mathematically rigorous cheat sheet based on Real Analysis Sections 8.1–8.8. It is designed for quick reference/exam preparation.

---

# Real Analysis Cheat Sheet: Sequences & Series of Functions

## 8.1 Pointwise Convergence & The Interchange Problem

### Definitions
* **Pointwise Convergence:** A sequence $\{f_n\}$ converges pointwise to $f$ on $E$ if for every $x \in E$:
    $$\lim_{n \to \infty} f_n(x) = f(x)$$
    * *Formal:* $\forall x \in E, \forall \epsilon > 0, \exists n_0(x, \epsilon)$ such that $|f_n(x) - f(x)| < \epsilon$ for $n \ge n_0$.
    * *Note:* $n_0$ depends on $x$.

### Failure of Pointwise Convergence (Counter-Examples)
Pointwise convergence is **insufficient** to preserve analytic properties.

1.  **Continuity is NOT preserved**
    * *Example:* $f_n(x) = x^n$ on $[0, 1]$.
    * *Limit:* $f(x) = 0$ for $x \in [0, 1)$ and $f(1) = 1$.
    * *Result:* Each $f_n$ is continuous, but limit $f$ is discontinuous at $x=1$.

2.  **Integrals do NOT converge ($\lim \int \neq \int \lim$)**
    * *Example:* $f_n(x) = nx(1-x^2)^n$ on $[0, 1]$. Pointwise limit $f(x) = 0$.
    * *Integration:* $\int_0^1 f_n(x) dx = \frac{n}{2(n+1)} \to \frac{1}{2}$.
    * *Result:* $\lim \int f_n = 1/2 \neq \int f = 0$.

3.  **Differentiability is NOT preserved**
    * *Example:* $f_n(x) = \frac{\sin(nx)}{n}$. Pointwise limit $f(x) = 0$ ($f'(x)=0$).
    * *Differentiation:* $f_n'(x) = \cos(nx)$. At $x=0$, $f_n'(0) = 1$.
    * *Result:* $\lim f_n'(0) = 1 \neq f'(0) = 0$.

---

## 8.2 Uniform Convergence

### Definition & Interpretation
* **Uniform Convergence:** $\{f_n\} \to f$ uniformly on $E$ if:
    $$\forall \epsilon > 0, \exists n_0(\epsilon) \text{ s.t. } \forall x \in E, \forall n \ge n_0, |f_n(x) - f(x)| < \epsilon$$
    * *Note:* $n_0$ depends **only** on $\epsilon$, not $x$.
    * *Geometric:* Graph of $f_n$ lies in a "tube" of width $2\epsilon$ around $f$.

### Convergence Tests
1.  **Supremum Norm Test (The "Sup Test")**
    Define $M_n = \sup_{x \in E} |f_n(x) - f(x)|$.
    $$f_n \to f \text{ uniformly} \iff \lim_{n \to \infty} M_n = 0$$
    * *Ex (Failure):* "Sliding Hump" $S_n(x) = nxe^{-nx^2}$. Max height $\sqrt{n/2e} \to \infty$. Not uniform.

2.  **Cauchy Criterion**
    $\{f_n\}$ converges uniformly on $E$ iff $\forall \epsilon > 0, \exists n_0$ such that:
    $$|f_n(x) - f_m(x)| < \epsilon \quad \forall n, m \ge n_0, \forall x \in E$$

3.  **Weierstrass M-Test (For Series)**
    Let $f(x) = \sum f_k(x)$. If there exist constants $M_k$ such that:
    1.  $|f_k(x)| \le M_k$ for all $x \in E$.
    2.  $\sum M_k < \infty$.
    * **Then:** $\sum f_k$ converges **uniformly** and **absolutely**.

---

## 8.3 Continuity & $\mathcal{C}(K)$ Space

### Theorems
1.  **Preservation of Continuity:**
    If $f_n \to f$ uniformly and each $f_n$ is continuous, then $f$ is continuous.
    * *Corollary:* Intechange of limits: $\lim_{t \to p} \lim_{n \to \infty} f_n(t) = \lim_{n \to \infty} \lim_{t \to p} f_n(t)$.

2.  **Dini's Theorem:**
    Uniform convergence is guaranteed if:
    * $K$ is **compact**.
    * $f_n$ are continuous and converge **pointwise** to continuous $f$.
    * Sequence is **monotone** ($f_n(x) \ge f_{n+1}(x)$ for all $n, x$).

### The Space $\mathcal{C}(K)$
Let $K$ be compact. $\mathcal{C}(K)$ is the space of continuous functions equipped with the **Uniform Norm**:
$$||f||_u = \max_{x \in K} |f(x)|$$
* **Completeness:** $\mathcal{C}(K)$ is a **complete** metric space (Banach space). Every uniformly Cauchy sequence of continuous functions converges to a continuous function.

### Contraction Mappings
* **Banach Fixed Point Theorem:**
    Let $X$ be a complete normed space. If $T: X \to X$ is a contraction ($||T(x)-T(y)|| \le c||x-y||$ with $0<c<1$), then $T$ has a **unique fixed point** ($T(x)=x$).

---

## 8.4 Integration

### Theorems
1.  **Uniform Convergence & Integration:**
    If $f_n \in \mathcal{R}[a, b]$ and $f_n \to f$ **uniformly**, then $f \in \mathcal{R}[a, b]$ and:
    $$\lim_{n \to \infty} \int_a^b f_n(x) dx = \int_a^b f(x) dx$$
    * Also applies to series: $\int \sum f_k = \sum \int f_k$.

2.  **Bounded Convergence Theorem (BCT):**
    Allows limit interchange *without* uniform convergence under specific conditions:
    * $f_n \to f$ pointwise.
    * $f_n$ and $f$ are Riemann integrable.
    * **Uniformly Bounded:** $\exists M$ s.t. $|f_n(x)| \le M$ for all $x, n$.
    * **Result:** $\lim \int f_n = \int f$.
    * *Revisits $x^n$:* Converges pointwise to discontinuous function, but $|x^n| \le 1$. Integrals converge $0 \to 0$. BCT holds.

---

## 8.5 Differentiation

**Uniform convergence of $f_n$ is NOT sufficient for $f_n' \to f'$.**

### Theorem 8.5.1 (Sufficient Condition)
Let $f_n$ be differentiable on $[a, b]$. If:
1.  $\{f_n(x_0)\}$ converges for some $x_0$.
2.  $\{f_n'\}$ converges **uniformly** on $[a, b]$.
**Then:** $\{f_n\}$ converges uniformly to $f$, and $f'(x) = \lim f_n'(x)$.

### Example 8.5.3 (Weierstrass Function)
A function continuous everywhere but differentiable nowhere:
$$f(x) = \sum_{k=0}^{\infty} \frac{\cos(a^k \pi x)}{2^k}$$
* Continuity: Proven via Weierstrass M-test (Uniform conv).
* Nowhere Differentiable: Oscillations become infinitely steep ($f'_n$ diverges).

---

## 8.6 Weierstrass Approximation

### Weierstrass Approximation Theorem
If $f$ is continuous on $[a, b]$, for every $\epsilon > 0$, there exists a polynomial $P$ such that:
$$||f - P||_u < \epsilon$$
* *Meaning:* Polynomials are dense in $\mathcal{C}[a, b]$.

### Proof Method: Approximate Identities
Uses convolution with a kernel $\{Q_n\}$ (Dirac sequence):
$$P_n(x) = \int_{-1}^{1} f(x+t) Q_n(t) dt$$
* Properties of $Q_n$: $\int Q_n = 1$, $Q_n \ge 0$, mass concentrates at 0 as $n \to \infty$.
* Landau Kernel: $Q_n(t) = c_n(1-t^2)^n$.

---

## 8.7 Power Series

Series form: $\sum_{k=0}^{\infty} a_k (x-c)^k$.

### Radius of Convergence ($R$)
Cauchy-Hadamard Formula:
$$\frac{1}{R} = \limsup_{k \to \infty} \sqrt[k]{|a_k|} \quad \text{or} \quad \frac{1}{R} = \lim \left| \frac{a_{k+1}}{a_k} \right|$$
* $|x-c| < R$: Absolute convergence.
* $|x-c| > R$: Divergence.
* $|x-c| \le \rho < R$: **Uniform convergence**.

### Key Theorems
1.  **Differentiation:** Power series are $C^\infty$ inside $R$. Derivatives are taken term-by-term; $R$ remains unchanged.
2.  **Abel's Theorem:** If series converges at endpoint $x = c+R$, the limit function is continuous at that point.
    $$\lim_{x \to R^-} \sum a_k x^k = \sum a_k R^k$$
3.  **Uniqueness:** If $\sum a_k x^k = \sum b_k x^k$, then $a_k = b_k$. Specifically $a_k = \frac{f^{(k)}(c)}{k!}$.

### Taylor Series Remainder
$f(x) = T_n(x) + R_n(x)$. Conv $\iff R_n \to 0$.
* **Lagrange Form:** $R_n(x) = \frac{f^{(n+1)}(\zeta)}{(n+1)!}(x-c)^{n+1}$.
* **Cauchy's Counter-example:** $f(x) = e^{-1/x^2}$ (at $x=0$). $f$ is $C^\infty$, all derivatives at 0 are 0. Taylor series is 0, but $f(x) \neq 0$.

---

## 8.8 The Gamma Function

Generalization of factorial to real numbers.
$$\Gamma(x) = \int_0^{\infty} t^{x-1} e^{-t} dt \quad (x > 0)$$

### Properties
1.  **Functional Eq:** $\Gamma(x+1) = x\Gamma(x)$.
2.  **Factorial:** $\Gamma(n+1) = n!$.
3.  **Value:** $\Gamma(1/2) = \sqrt{\pi}$.

### Beta Function
$$B(x, y) = \int_0^1 t^{x-1} (1-t)^{y-1} dt = \frac{\Gamma(x)\Gamma(y)}{\Gamma(x+y)}$$