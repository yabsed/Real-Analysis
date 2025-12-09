Here is a comprehensive study guide for **Chapter 9: Fourier Series**, organized by logical flow and key concepts. It covers definitions, calculation examples, convergence types, and the logic behind major theorems.

---

# 9.1 Orthogonal Functions

### 1. Inner Product and Orthogonality
To discuss "approximation," we treat functions as vectors.
* **Inner Product:** For $f, g \in \mathcal{R}[a,b]$ (Riemann integrable functions):
    $$\langle f, g \rangle = \int_{a}^{b} f(x)g(x) \, dx$$
* **Norm:** The "length" of a function is:
    $$\|f\|_2 = \sqrt{\langle f, f \rangle} = \left[ \int_{a}^{b} f^2(x) \, dx \right]^{1/2}$$
* **Orthogonality:** Two functions are orthogonal if $\langle f, g \rangle = 0$.
* **Orthonormal System:** A sequence $\{\phi_n\}$ is orthonormal if:
    $$\langle \phi_n, \phi_m \rangle = \begin{cases} 0 & n \neq m \\ 1 & n = m \end{cases}$$

### 2. Examples of Orthogonal Systems
* **Example A:** $\{1, x\}$ on $[-1, 1]$.
    $$\int_{-1}^{1} 1 \cdot x \, dx = \left[ \frac{x^2}{2} \right]_{-1}^{1} = 0$$
* **Example B (Trigonometric System):** $\{ \sin nx \}_{n=1}^{\infty}$ on $[-\pi, \pi]$.
    For $n \neq m$, using product-to-sum identities:
    $$\int_{-\pi}^{\pi} \sin nx \sin mx \, dx = 0$$
    For $n = m$:
    $$\int_{-\pi}^{\pi} \sin^2 nx \, dx = \pi$$
* **Example C:** $\{ 1, \cos \frac{n\pi x}{L}, \sin \frac{n\pi x}{L} \}$ on $[-L, L]$.

### 3. Approximation in the Mean (Least Squares)
Given an orthogonal system $\{\phi_n\}$, we want to approximate $f$ using a partial sum $S_N(x) = \sum_{n=1}^{N} c_n \phi_n(x)$.
We want to minimize the **mean square error**:
$$E_N = \| f - S_N \|_2^2 = \int_{a}^{b} [f(x) - S_N(x)]^2 \, dx$$

**Theorem:** The error is minimized if and only if $c_n$ are the **Fourier Coefficients**:
$$c_n = \frac{\langle f, \phi_n \rangle}{\|\phi_n\|^2} = \frac{\int_{a}^{b} f(x)\phi_n(x) \, dx}{\int_{a}^{b} \phi_n^2(x) \, dx}$$

**Proof Idea:**
Expand the integral $\int (f - \sum c_n \phi_n)^2$. By completing the square with respect to $c_n$, one finds that the minimum occurs exactly when $c_n$ takes the form above.

### 4. Bessel's Inequality
Since the error $E_N \ge 0$:
$$\sum_{n=1}^{\infty} c_n^2 \|\phi_n\|^2 \le \|f\|^2_2$$
**Corollary:** The coefficients $c_n$ must decay such that $\lim_{n \to \infty} c_n = 0$.

---

# 9.2 Completeness and Parseval's Equality

### 1. Convergence in the Mean
A sequence $\{f_n\}$ converges to $f$ **in the mean** if:
$$\lim_{n \to \infty} \int_{a}^{b} [f(x) - f_n(x)]^2 \, dx = 0 \quad \iff \quad \lim_{n \to \infty} \|f - f_n\|_2 = 0$$
*Note: Uniform convergence $\implies$ Mean convergence. However, Mean convergence does NOT imply Pointwise convergence.*

### 2. Completeness
An orthogonal system $\{\phi_n\}$ is **complete** if the Fourier series partial sums $S_N$ converge to $f$ in the mean for every $f \in \mathcal{R}[a,b]$.

### 3. Parseval's Equality
The system is complete if and only if **Parseval's Equality** holds for all $f$:
$$\sum_{n=1}^{\infty} c_n^2 \|\phi_n\|^2 = \int_{a}^{b} f^2(x) \, dx$$
*Concept:* This is the infinite-dimensional version of the Pythagorean theorem ($\|v\|^2 = \sum |components|^2$).

---

# 9.3 Trigonometric Fourier Series

### 1. The Definitions
For the system $\{1, \cos nx, \sin nx\}$ on $[-\pi, \pi]$:
$$f(x) \sim \frac{a_0}{2} + \sum_{n=1}^{\infty} (a_n \cos nx + b_n \sin nx)$$
**Formulas:**
* $a_0 = \frac{1}{\pi} \int_{-\pi}^{\pi} f(x) \, dx$
* $a_n = \frac{1}{\pi} \int_{-\pi}^{\pi} f(x) \cos nx \, dx$
* $b_n = \frac{1}{\pi} \int_{-\pi}^{\pi} f(x) \sin nx \, dx$

### 2. Calculation Examples

**Example A: Step Function**
$$f(x) = \begin{cases} 0 & -\pi \le x < 0 \\ 1 & 0 \le x < \pi \end{cases}$$
* **$a_0$:** $\frac{1}{\pi} \int_0^{\pi} 1 \, dx = 1$.
* **$a_n$:** $\frac{1}{\pi} \int_0^{\pi} \cos nx \, dx = \frac{1}{n\pi}[\sin nx]_0^{\pi} = 0$.
* **$b_n$:** $\frac{1}{\pi} \int_0^{\pi} \sin nx \, dx = \frac{-1}{n\pi}[\cos nx]_0^{\pi} = \frac{1}{n\pi}(1 - (-1)^n)$.
    * If $n$ is even, $b_n = 0$.
    * If $n$ is odd ($2k+1$), $b_n = \frac{2}{(2k+1)\pi}$.
* **Series:** $f(x) \sim \frac{1}{2} + \frac{2}{\pi} \sum_{k=0}^{\infty} \frac{\sin(2k+1)x}{2k+1}$.

**Example B: $f(x) = x$ on $[-\pi, \pi]$**
* **Symmetry:** $f(x)$ is **Odd**.
    * $a_n = 0$ (integral of odd $\times$ even is odd, symmetric integral is 0).
* **$b_n$:** Use integration by parts.
    $$b_n = \frac{2}{\pi} \int_{0}^{\pi} x \sin nx \, dx = \frac{2}{\pi} \left[ -\frac{x \cos nx}{n} \Big|_0^{\pi} + \frac{1}{n} \int_0^{\pi} \cos nx \, dx \right]$$
    $$b_n = \frac{2}{\pi} \left( -\frac{\pi (-1)^n}{n} \right) = \frac{2(-1)^{n+1}}{n}$$
* **Series:** $x \sim 2 \sum_{n=1}^{\infty} \frac{(-1)^{n+1}}{n} \sin nx$.

### 3. Riemann-Lebesgue Lemma
For any $f \in \mathcal{R}[-\pi, \pi]$:
$$\lim_{n \to \infty} \int_{-\pi}^{\pi} f(x) \cos nx \, dx = \lim_{n \to \infty} \int_{-\pi}^{\pi} f(x) \sin nx \, dx = 0$$
*Implication:* Fourier coefficients $a_n, b_n \to 0$ as $n \to \infty$.

### 4. Sine and Cosine Series (Half-Range Expansions)
If $f$ is defined only on $[0, \pi]$:
* **Even Extension ($f_e$):** Extends $f$ to $[-\pi, \pi]$ as an even function. Generates a **Cosine Series**.
* **Odd Extension ($f_o$):** Extends $f$ to $[-\pi, \pi]$ as an odd function. Generates a **Sine Series**.

---

# 9.4 Convergence in the Mean

### 1. The Dirichlet Kernel ($D_n$)
The partial sum $S_n(x)$ can be written as an integral convolution:
$$S_n(x) = \frac{1}{\pi} \int_{-\pi}^{\pi} f(t) D_n(x-t) \, dt$$
where $D_n(t) = \frac{1}{2} + \sum_{k=1}^{n} \cos kt = \frac{\sin((n + 1/2)t)}{2 \sin(t/2)}$.
*Properties:* $\frac{1}{\pi} \int D_n = 1$, but $\int |D_n| \to \infty$. This makes $D_n$ "bad" for proving uniform convergence directly.

### 2. The Fejér Kernel ($F_n$)
To fix the behavior of $D_n$, we take the arithmetic mean (Cesàro mean) of the partial sums:
$$\sigma_n(x) = \frac{S_0(x) + \dots + S_n(x)}{n+1}$$
$$\sigma_n(x) = \frac{1}{\pi} \int_{-\pi}^{\pi} f(t) F_n(x-t) \, dt$$
where $F_n(t) = \frac{1}{2(n+1)} \left[ \frac{\sin((n+1)t/2)}{\sin(t/2)} \right]^2$.

**Properties of $F_n$ (Approximate Identity):**
1.  $F_n(t) \ge 0$.
2.  $\frac{1}{\pi} \int_{-\pi}^{\pi} F_n(t) \, dt = 1$.
3.  For any $\delta > 0$, $F_n(t) \to 0$ uniformly outside $[-\delta, \delta]$.

### 3. Fejér's Theorem
If $f$ is continuous on $[-\pi, \pi]$ and periodic ($f(-\pi)=f(\pi)$), then:
$$\sigma_n(x) \to f(x) \quad \text{uniformly on } [-\pi, \pi].$$
*Proof Idea:* Use the properties of the Approximate Identity. Split the integral into a small region near 0 (where $f(x-t) \approx f(x)$) and the tail (where $F_n \to 0$).

### 4. Main Result: Mean Convergence
**Theorem:** For any $f \in \mathcal{R}[-\pi, \pi]$, the Fourier series converges to $f$ **in the mean**.
$$\lim_{n \to \infty} \int_{-\pi}^{\pi} [f(x) - S_n(x)]^2 \, dx = 0$$
**Corollary (Parseval's Equality for Trig Series):**
$$\frac{a_0^2}{2} + \sum_{n=1}^{\infty} (a_n^2 + b_n^2) = \frac{1}{\pi} \int_{-\pi}^{\pi} f^2(x) \, dx$$

**Calculation Example using Parseval:**
Using $f(x) = x$ and its coefficients $b_n = \frac{2(-1)^{n+1}}{n}$:
$$\sum_{n=1}^{\infty} \left( \frac{2}{n} \right)^2 = \frac{1}{\pi} \int_{-\pi}^{\pi} x^2 \, dx = \frac{2\pi^2}{3}$$
$$4 \sum \frac{1}{n^2} = \frac{2\pi^2}{3} \implies \sum_{n=1}^{\infty} \frac{1}{n^2} = \frac{\pi^2}{6}$$

---

# 9.5 Pointwise Convergence

### 1. The Problem
Convergence in the mean does not guarantee that $S_n(x) \to f(x)$ at every specific point $x$. We need stronger conditions.

### 2. Dirichlet's Theorem (Sufficient Conditions)
If $f$ is periodic ($2\pi$) and piecewise continuous on $[-\pi, \pi]$, and $x_0$ is a point where:
1.  One-sided limits $f(x_0^+)$ and $f(x_0^-)$ exist.
2.  One-sided derivatives (or Lipschitz conditions) exist.
    $$|f(x_0 \pm t) - f(x_0^\pm)| \le M t$$

Then the Fourier series converges to the average of the jump:
$$\lim_{n \to \infty} S_n(x_0) = \frac{f(x_0^+) + f(x_0^-)}{2}$$
*Note:* If $f$ is continuous at $x_0$, it converges to $f(x_0)$.

### 3. Application Examples
* **Example A (Discontinuous):**
    $f(x) = 0$ on $[-\pi, -\pi/2)$, $3$ on $[-\pi/2, \pi/2]$, $0$ on $(\pi/2, \pi)$.
    At $x = \pi/2$, the series converges to $\frac{3 + 0}{2} = 1.5$.
    At $x = 0$, the series converges to $3$.
* **Example B (Continuous):**
    $f(x) = |x|$ on $[-\pi, \pi]$. Continuous everywhere and derivative is piecewise continuous ($\pm 1$).
    Series converges to $|x|$ everywhere. Here are concise, comprehensive study notes on **Chapter 9: Fourier Series**, based on the provided text. These notes focus on mathematical definitions, key theorems, proof logic, and all illustrative examples included in the source.

---

# Chapter 9: Fourier Series

## 9.1 Orthogonal Functions
**Core Concept:** Approximating functions using a linear combination of orthogonal functions, analogous to vector decomposition in $\mathbb{R}^n$.

### 1. Inner Product and Orthogonality
For Riemann integrable functions on $[a, b]$, denoted $\mathcal{R}[a, b]$, the **inner product** is defined as:
$$\langle f, g \rangle = \int_{a}^{b} f(x)g(x) \, dx$$
* **Norm:** $||f||_2 = \sqrt{\langle f, f \rangle} = \left[ \int_{a}^{b} f^2(x) \, dx \right]^{1/2}$.
* **Orthogonality:** Two functions $\phi, \psi$ are orthogonal if $\langle \phi, \psi \rangle = 0$.
* **Orthonormality:** A sequence $\{\phi_n\}$ is orthonormal if $\langle \phi_n, \phi_m \rangle = 0$ for $n \neq m$ and $||\phi_n||^2 = 1$.

### 2. Key Examples of Orthogonal Systems
* **Example 9.1.2(a):** $\{1, x\}$ on $[-1, 1]$.
    $$\int_{-1}^{1} 1 \cdot x \, dx = \left[ \frac{x^2}{2} \right]_{-1}^{1} = 0$$
* **Example 9.1.2(b):** $\{ \sin nx \}_{n=1}^{\infty}$ on $[-\pi, \pi]$.
    $$\int_{-\pi}^{\pi} \sin nx \sin mx \, dx = 0 \quad (\text{for } n \neq m)$$
    *Norm squared:* $\int_{-\pi}^{\pi} \sin^2 nx \, dx = \pi$.
* **Example 9.1.2(c):** $\{ 1, \sin \frac{n\pi x}{L}, \cos \frac{n\pi x}{L} \}$ on $[-L, L]$.
    This is the general trigonometric system.

### 3. Approximation in the Mean
We seek constants $c_n$ to minimize the mean square error between $f$ and the partial sum $S_N(x) = \sum_{n=1}^{N} c_n \phi_n(x)$:
$$E_N = || f - S_N ||_2^2 = \int_{a}^{b} [f(x) - S_N(x)]^2 \, dx$$

**Theorem 9.1.4 (Best Approximation):**
The error is minimized if and only if $c_n$ are the **Fourier Coefficients**:
$$c_n = \frac{\langle f, \phi_n \rangle}{||\phi_n||^2} = \frac{\int_{a}^{b} f(x)\phi_n(x) \, dx}{\int_{a}^{b} \phi_n^2(x) \, dx}$$
With these coefficients, the error identity is:
$$||f - S_N||^2 = ||f||^2 - \sum_{n=1}^{N} c_n^2 ||\phi_n||^2$$

**Example 9.1.6:**
Approximating $f(x) = x^3 + 1$ on $[-1, 1]$ using orthogonal system $\{1, x\}$.
* $c_1 = \frac{\int (x^3+1)(1)}{\int 1^2} = 1$
* $c_2 = \frac{\int (x^3+1)(x)}{\int x^2} = \frac{3}{5}$
* Result: $S_2(x) = 1 + \frac{3}{5}x$.

### 4. Bessel's Inequality
Since the error $||f - S_N||^2 \ge 0$, it follows that:
$$\sum_{n=1}^{\infty} c_n^2 ||\phi_n||^2 \le ||f||^2$$
**Corollary:** For orthogonal systems, Fourier coefficients $c_n \to 0$ as $n \to \infty$ (normalized by norm).

---

## 9.2 Completeness and Parseval's Equality

### 1. Convergence in the Mean
A sequence $f_n$ converges to $f$ **in the mean** if:
$$\lim_{n \to \infty} \int_{a}^{b} [f(x) - f_n(x)]^2 \, dx = 0 \quad \iff \quad \lim_{n \to \infty} ||f - f_n||_2 = 0$$
* **Theorem:** Uniform convergence $\implies$ Convergence in the mean.
* **Counter-Example 9.2.3 (Mean $\nRightarrow$ Pointwise):**
    A sequence of "moving bump" functions $f_n$ on $[0, 1]$.
    * Constructed by dividing $[0, 1]$ into intervals of size $1/2^k$. $f_n$ is 1 on a shrinking sub-interval and 0 elsewhere.
    * $\int f_n^2 \to 0$ (Converges in mean to 0).
    * For any $x$, $f_n(x)$ oscillates between 0 and 1 infinitely often (Diverges pointwise).

### 2. Completeness
An orthogonal system $\{\phi_n\}$ is **complete** if Parseval's Equality holds for *every* $f \in \mathcal{R}[a, b]$.
**Parseval's Equality:**
$$\sum_{n=1}^{\infty} c_n^2 ||\phi_n||^2 = ||f||^2$$
* Completeness is equivalent to the partial sums $S_N$ converging to $f$ in the mean.
* **Uniqueness Theorem:** If $\{\phi_n\}$ is complete and $f$ is continuous, and all Fourier coefficients are zero ($\int f \phi_n = 0$), then $f(x) \equiv 0$.

---

## 9.3 Trigonometric and Fourier Series

### 1. The Trigonometric System
On $[-\pi, \pi]$, the system is $\{1, \cos nx, \sin nx\}$.
* $||1||^2 = 2\pi$
* $||\cos nx||^2 = \pi$, $||\sin nx||^2 = \pi$

### 2. Definitions
For $f \in \mathcal{R}[-\pi, \pi]$:
$$a_0 = \frac{1}{\pi} \int_{-\pi}^{\pi} f(x) \, dx$$
$$a_n = \frac{1}{\pi} \int_{-\pi}^{\pi} f(x) \cos nx \, dx, \quad b_n = \frac{1}{\pi} \int_{-\pi}^{\pi} f(x) \sin nx \, dx$$
**Fourier Series:**
$$f(x) \sim \frac{a_0}{2} + \sum_{n=1}^{\infty} (a_n \cos nx + b_n \sin nx)$$

### 3. Examples of Calculation
* **Example 9.3.3(a): Step Function**
    $f(x) = 0$ for $x \in [-\pi, 0)$, $f(x) = 1$ for $x \in [0, \pi)$.
    * $a_0 = 1$.
    * $a_n = 0$ (calculation yields $\sin n\pi = 0$).
    * $b_n = \frac{1}{n\pi}[1 - (-1)^n]$. (Non-zero only for odd $n$).
    * Series: $\frac{1}{2} + \frac{2}{\pi} \sum_{k=0}^{\infty} \frac{\sin(2k+1)x}{2k+1}$.

* **Example 9.3.3(b): $f(x) = x$**
    * $f$ is odd $\implies a_n = 0$.
    * $b_n = \frac{2}{\pi} \int_{0}^{\pi} x \sin nx \, dx$. Integration by parts yields $b_n = \frac{2(-1)^{n+1}}{n}$.
    * Series: $2 \sum_{n=1}^{\infty} \frac{(-1)^{n+1}}{n} \sin nx$.

### 4. Riemann-Lebesgue Lemma
For $f \in \mathcal{R}[-\pi, \pi]$:
$$\lim_{n \to \infty} \int_{-\pi}^{\pi} f(x) \cos nx \, dx = \lim_{n \to \infty} \int_{-\pi}^{\pi} f(x) \sin nx \, dx = 0$$
* **Example 9.3.5:** If $f$ is not integrable (e.g., $f(x) = 1/x$), the limit may not be zero ($\lim \to \pi/2$). This confirms integrability is required.

### 5. Sine and Cosine Series
* If $f$ is defined on $[0, \pi]$:
    * **Odd Extension:** Yields **Sine Series** ($a_n = 0$).
    * **Even Extension:** Yields **Cosine Series** ($b_n = 0$).

---

## 9.4 Convergence in the Mean
**Goal:** Prove that for $f \in \mathcal{R}[-\pi, \pi]$, the Fourier series converges to $f$ in the mean.

### 1. The Dirichlet Kernel ($D_n$)
The partial sum $S_n(x)$ can be written as an integral convolution:
$$S_n(x) = \frac{1}{\pi} \int_{-\pi}^{\pi} f(t) D_n(x-t) \, dt$$
$$D_n(t) = \frac{1}{2} + \sum_{k=1}^{n} \cos kt = \frac{\sin((n+1/2)t)}{2 \sin(t/2)}$$
* **Problem:** $D_n$ is *not* a "good" kernel (approximate identity) because $\int |D_n| \to \infty$. This makes pointwise convergence difficult to prove directly.

### 2. The Fejér Kernel ($F_n$)
To solve the convergence problem, we look at **Cesàro means** (averages of partial sums):
$$\sigma_n(x) = \frac{S_0(x) + \dots + S_n(x)}{n+1}$$
$$\sigma_n(x) = \frac{1}{\pi} \int_{-\pi}^{\pi} f(t) F_n(x-t) \, dt$$
$$F_n(t) = \frac{1}{2(n+1)} \left[ \frac{\sin(\frac{n+1}{2}t)}{\sin(t/2)} \right]^2$$
**Properties of $F_n$ (Approximate Identity):**
1.  $F_n(t) \ge 0$.
2.  $\frac{1}{\pi} \int F_n = 1$.
3.  $F_n \to 0$ uniformly outside any neighborhood of $t=0$.

### 3. Fejér's Theorem
**Theorem 9.4.5:** If $f$ is continuous on $[-\pi, \pi]$ and $f(-\pi) = f(\pi)$, then $\sigma_n(x)$ converges uniformly to $f(x)$.

**Proof Logic:**
Using the properties of the Fejér kernel (Approximate Identity), the convolution $\sigma_n$ approximates any continuous periodic function uniformly.

**Corollary 9.4.6:** Since $\sigma_n \to f$ uniformly, $S_n$ converges to $f$ **in the mean** for continuous functions. (The mean square error of $S_n$ is always $\le$ the mean square error of $\sigma_n$).

### 4. General Convergence and Parseval's
**Theorem 9.4.7:** For *any* $f \in \mathcal{R}[-\pi, \pi]$, $S_n$ converges to $f$ in the mean.
**Proof Idea:** Any Riemann integrable function can be approximated in the mean by a continuous function (Step function approximation lemma). Combined with Fejér's theorem, the result follows.

**Parseval's Equality (Corollary 9.4.9):**
$$\frac{a_0^2}{2} + \sum_{n=1}^{\infty} (a_n^2 + b_n^2) = \frac{1}{\pi} \int_{-\pi}^{\pi} f^2(x) \, dx$$

**Example 9.4.10:**
Using $f(x) = x$ (from 9.3.3b), $b_n = \frac{2(-1)^{n+1}}{n}$.
Apply Parseval's: $\sum \frac{4}{n^2} = \frac{1}{\pi} \int_{-\pi}^{\pi} x^2 \, dx = \frac{2\pi^2}{3}$.
Result: $\sum_{n=1}^{\infty} \frac{1}{n^2} = \frac{\pi^2}{6}$.

---

## 9.5 Pointwise Convergence
**Question:** When does $S_n(x) \to f(x)$ at a specific point $x$?

### 1. Dirichlet's Theorem
**Theorem 9.5.3:** Let $f$ be periodic ($2\pi$). If at a point $x_0$:
1.  Left and right limits $f(x_0-), f(x_0+)$ exist.
2.  Left and right derivatives (or Lipschitz conditions) exist.
    * $|f(x_0 \pm t) - f(x_0 \pm)| \le Mt$.

Then:
$$\lim_{n \to \infty} S_n(x_0) = \frac{f(x_0+) + f(x_0-)}{2}$$

**Proof Logic:**
Using the Dirichlet integral representation:
$$S_n(x) - A = \frac{2}{\pi} \int_{0}^{\pi} \left[ \frac{f(x+t) + f(x-t)}{2} - A \right] D_n(t) \, dt$$
Set $A = \text{avg limit}$. The term in the bracket divided by $2\sin(t/2)$ behaves like a Riemann integrable function $g(t)$ due to the derivative condition (boundedness near 0).
By Riemann-Lebesgue Lemma, $\int g(t) \sin((n+1/2)t) dt \to 0$.

### 2. Piecewise Continuity
* **Piecewise Continuous:** Finite number of simple discontinuities (finite jumps).
* **Piecewise Smooth:** $f$ and $f'$ are piecewise continuous.
* **Corollary 9.5.6:** If $f$ is periodic and piecewise smooth, Fourier series converges to the average of limits everywhere.

### 3. Examples
* **Example 9.5.7(a):** Square wave (0, 3, 0).
    * At discontinuity (e.g., $x = \pi/2$), series converges to $3/2$.
    * Evaluating at $x=0$ yields Leibniz series: $\sum \frac{(-1)^k}{2k+1} = \frac{\pi}{4}$.
* **Example 9.5.7(b):** Triangular wave ($f(x)=|x|$ on $[-\pi, \pi]$).
    * Continuous everywhere. Series converges to $|x|$.
    * Evaluating at $x=0$ yields $\sum \frac{1}{(2k-1)^2} = \frac{\pi^2}{8}$.

### 4. Differentiation of Fourier Series
**Theorem 9.5.8:**
Differentiation term-by-term is valid if:
1.  $f$ is continuous on $[-\pi, \pi]$ AND $f(-\pi) = f(\pi)$ (Periodic continuity).
2.  $f'$ is piecewise continuous.

Then at points where $f''(x)$ exists:
$$f'(x) = \sum_{n=1}^{\infty} (-n a_n \sin nx + n b_n \cos nx)$$
*Note: If $f$ is discontinuous, the differentiated series generally diverges.*

**Example 9.5.9:**
* $f(x) = x^2$ is continuous and periodic.
* Differentiating the series for $x^2$ leads to the series for $2x$ (which matches the calculated series for $x$).
* Conversely, integrating the series for $2x$ term-by-term yields the series for $x^2$.Evaluating at $x=0$ often yields sums of series like $\sum \frac{1}{(2k-1)^2}$.

### 4. Differentiation of Fourier Series
Simply differentiating a Fourier series term-by-term is not always valid (the resulting series might diverge).
**Theorem:** If $f$ is **continuous** everywhere (including $f(-\pi)=f(\pi)$) and $f'$ is **piecewise continuous**, then the Fourier series of $f'$ is obtained by differentiating the series of $f$ term-by-term.
$$f'(x) \sim \sum (-n a_n \sin nx + n b_n \cos nx)$$