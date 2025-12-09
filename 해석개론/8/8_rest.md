Here is a detailed, mathematically rigorous study note based on the provided text, covering **Sections 8.5 through 8.8**.

---

# 8.5 Uniform Convergence and Differentiation

This section addresses the conditions under which limits and differentiation can be interchanged.

### The Problem of Interchange
Uniform convergence of a sequence $\{f_n\}$ to $f$ is **not sufficient** to guarantee that $\{f_n'\}$ converges to $f'$.
* **Example:** Consider $f_n(x) = \frac{x^n}{n}$ on $[0,1]$. $f_n \to 0$ uniformly, but $f_n'(1) = 1$ while $f'(1) = 0$.

### Theorem 8.5.1: Sufficient Conditions
Let $\{f_n\}$ be a sequence of differentiable functions on $[a, b]$. If:
1.  $\{f_n'\}$ converges **uniformly** on $[a, b]$, and
2.  $\{f_n(x_0)\}$ converges for at least one point $x_0 \in [a, b]$,

Then $\{f_n\}$ converges uniformly to a function $f$ on $[a, b]$, and $f'(x) = \lim_{n \to \infty} f_n'(x)$.

**Proof Idea:**
The proof relies on the **Mean Value Theorem (MVT)** applied to the difference $f_n - f_m$.
1.  Let $\epsilon > 0$. Using the Cauchy criterion for uniform convergence of $f_n'$, for large $n, m$, $|f_n'(t) - f_m'(t)| < \frac{\epsilon}{2(b-a)}$.
2.  By MVT, $|(f_n(x) - f_m(x)) - (f_n(y) - f_m(y))| \leq |x-y| \sup |f_n' - f_m'|$.
3.  This inequality allows showing that $\{f_n\}$ is uniformly Cauchy. Let $f$ be the limit.
4.  To prove $f'(p) = \lim f_n'(p)$, define difference quotients $g_n(t)$. Uniform convergence of derivatives allows swapping the limit order: $\lim_{t \to p} \lim_{n \to \infty} g_n(t) = \lim_{n \to \infty} \lim_{t \to p} g_n(t)$.

### Example 8.5.3: A Continuous Nowhere Differentiable Function
Weierstrass constructed a function that is continuous everywhere but differentiable nowhere.
$$f(x) = \sum_{k=0}^{\infty} \frac{\cos(a^k \pi x)}{2^k}$$
where $a$ is an odd integer and $a > 3\pi + 2$.
* **Continuity:** Since $|\frac{\cos(\dots)}{2^k}| \leq \frac{1}{2^k}$, the series converges uniformly by the Weierstrass M-test.
* **Non-differentiability:** The derivative fails to exist because the oscillations become infinitely steep at every scale. The proof involves constructing a sequence $h_n \to 0$ such that the difference quotient $\frac{f(x+h_n)-f(x)}{h_n} \to \infty$.


---

# 8.6 The Weierstrass Approximation Theorem

**Theorem 8.6.1:** If $f$ is a continuous real-valued function on $[a, b]$, then for every $\epsilon > 0$, there exists a polynomial $P$ such that $|f(x) - P(x)| < \epsilon$ for all $x \in [a, b]$.
* *Interpretation:* Polynomials are dense in the space of continuous functions $C[a, b]$ under the uniform norm.

To prove this, we utilize **Approximate Identities**.

### Periodic Functions and Approximate Identities
**Definition:** A sequence $\{Q_n\}$ of nonnegative Riemann integrable functions on $[-1, 1]$ is an **Approximate Identity** (or Dirac sequence) if:
1.  $\int_{-1}^{1} Q_n(t) dt = 1$
2.  $\lim_{n \to \infty} \int_{\{\delta \le |t|\}} Q_n(t) dt = 0$ for every $\delta > 0$.


**Theorem 8.6.5:** Let $f$ be a continuous, periodic function (period 2). The convolution
$$S_n(x) = \int_{-1}^{1} f(x+t) Q_n(t) dt$$
converges uniformly to $f(x)$ on $\mathbb{R}$.

**Proof Idea:**
1.  Write $S_n(x) - f(x) = \int_{-1}^{1} [f(x+t) - f(x)] Q_n(t) dt$ (using property 1).
2.  Split the integral into $[-\delta, \delta]$ and the "tails" $\{\delta \le |t|\}$.
3.  Near 0, continuity ensures $|f(x+t)-f(x)|$ is small.
4.  In the tails, the approximate identity property ensures the integral vanishes as $n \to \infty$.

### Proof of Weierstrass Approximation Theorem
1.  **Normalization:** Transform $f$ defined on $[a, b]$ to $[0, 1]$. Adjust $f$ so $f(0)=f(1)=0$ and extend it to be periodic on $\mathbb{R}$.
2.  **Specific Kernel:** Choose the polynomial kernel $Q_n(t) = c_n(1-t^2)^n$, where $c_n$ normalizes the integral to 1.
3.  **Estimate:** It is shown that $c_n < \sqrt{n}$, ensuring the mass concentrates at 0 properly.
4.  **Polynomial Result:** The convolution $P_n(x) = \int_{-1}^{1} f(x+t)Q_n(t) dt$ becomes a polynomial in $x$ because $Q_n(t)$ is a polynomial.

---

# 8.7 Power Series Expansions

**Definition:** A series $\sum_{k=0}^{\infty} a_k (x-c)^k$ is a power series centered at $c$.

### Radius of Convergence
The radius of convergence $R$ is defined by the Cauchy-Hadamard formula:
$$\frac{1}{R} = \limsup_{k \to \infty} \sqrt[k]{|a_k|}$$
Alternatively, using the ratio test (if the limit exists): $\frac{1}{R} = \lim |\frac{a_{k+1}}{a_k}|$.

**Theorem 8.7.3:**
* If $|x-c| < R$, the series converges absolutely.
* If $|x-c| > R$, the series diverges.
* If $0 < \rho < R$, the series converges **uniformly** on $|x-c| \le \rho$.

### Abel's Theorem (Theorem 8.7.5)
If a power series (radius $R$) converges at an endpoint (e.g., $x = c+R$), then the function defined by the series is **continuous** at that endpoint.
$$\lim_{x \to R^-} \sum a_k x^k = \sum a_k R^k$$

### Differentiation and Uniqueness
**Theorem 8.7.7:** A power series can be differentiated term-by-term within its radius of convergence.
$$f'(x) = \sum_{k=1}^{\infty} k a_k (x-c)^{k-1}$$
* The derived series has the **same** radius of convergence $R$.
* **Corollary:** Functions defined by power series are infinitely differentiable ($C^\infty$) inside the interval of convergence.
* **Uniqueness:** If $\sum a_k x^k = \sum b_k x^k$ inside a neighborhood, then $a_k = b_k$ for all $k$. Specifically, $a_k = \frac{f^{(k)}(c)}{k!}$.

### Taylor Series and Remainder Estimates
Given $f \in C^\infty$, the **Taylor Series** is $\sum_{k=0}^{\infty} \frac{f^{(k)}(c)}{k!} (x-c)^k$.
Convergence to $f(x)$ depends on the remainder $R_n(x) = f(x) - T_n(x)$.

**Counter-example (Cauchy):**
$f(x) = e^{-1/x^2}$ for $x \neq 0$ and $f(0)=0$.
$f$ is $C^\infty$ and $f^{(n)}(0) = 0$ for all $n$. The Taylor series is identically 0, which does not converge to $f(x)$ (except at $x=0$).

**Remainder Formulas:**
To prove convergence ($R_n \to 0$), we use specific forms of the remainder:

1.  **Lagrange Form:** Exists $\zeta$ between $c$ and $x$ such that:
    $$R_n(x) = \frac{f^{(n+1)}(\zeta)}{(n+1)!}(x-c)^{n+1}$$
    *(Derived via repeated Mean Value Theorem)*

2.  **Integral Form:**
    $$R_n(x) = \frac{1}{n!} \int_c^x f^{(n+1)}(t)(x-t)^n dt$$
    *(Derived via Induction and Integration by Parts)*

3.  **Cauchy Form:** Exists $\zeta$ between $c$ and $x$ such that:
    $$R_n(x) = \frac{f^{(n+1)}(\zeta)}{n!} (x-c)(x-\zeta)^n$$

**Applications:**
* **Binomial Series:** $(1+x)^n = \sum \binom{n}{k} x^k$.
* **Sine:** $\sin x = \sum \frac{(-1)^k}{(2k+1)!} x^{2k+1}$. Convergence shown because $|f^{(n+1)}(\zeta)| \le 1$ and $\frac{x^n}{n!} \to 0$.
* **Natural Log:** $\ln(1+x) = \sum \frac{(-1)^{n+1}}{n} x^n$. Convergence on $(-1, 1]$.
    * For $x \in [0, 1]$, Lagrange form suffices.
    * For $x \in (-1, 0)$, Cauchy form is required to bound the remainder.

---

# 8.8 The Gamma Function

**Definition:** For $x > 0$,
$$\Gamma(x) = \int_0^{\infty} t^{x-1} e^{-t} dt$$


### Properties (Theorem 8.8.2)
1.  **Functional Equation:** $\Gamma(x+1) = x \Gamma(x)$.
    * *Proof:* Integration by parts with $u=t^x, dv=e^{-t}dt$.
2.  **Factorial Generalization:** $\Gamma(n+1) = n!$ for $n \in \mathbb{N}$.
3.  **Value at 1/2:** $\Gamma(\frac{1}{2}) = \sqrt{\pi}$.
    * *Proof:* Substitution $t=s^2$ transforms the integral into a Gaussian integral $\int e^{-s^2} ds$, evaluated via polar coordinates in double integrals.

### The Binomial Series (General)
For any real $\alpha > 0$:
$$\frac{1}{(1-x)^\alpha} = \frac{1}{\Gamma(\alpha)} \sum_{n=0}^{\infty} \frac{\Gamma(n+\alpha)}{n!} x^n \quad \text{for } |x| < 1$$
This generalizes the binomial theorem to non-integer exponents.

### The Beta Function
Defined as $B(x, y) = \int_0^1 t^{x-1} (1-t)^{y-1} dt$ for $x, y > 0$.
**Theorem 8.8.5:** Relationship to Gamma:
$$\int_0^1 t^{x-1} (1-t)^{y-1} dt = \frac{\Gamma(x)\Gamma(y)}{\Gamma(x+y)}$$