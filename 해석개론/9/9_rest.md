Here is a comprehensive and structured study guide for **Chapter 9: Fourier Series**. This guide organizes the definitions, theorems, and examples into a logical flow for review.

---

# Chapter 9: Fourier Series

## 9.1 Orthogonal Functions
**Core Concept:** We can approximate complex functions using a linear combination of simpler, "orthogonal" functions, much like decomposing a vector into components in $\mathbb{R}^n$.

### 1. Inner Product and Norm
To treat functions like vectors, we define the **Inner Product** for Riemann integrable functions on $[a, b]$:
$$\langle f, g \rangle = \int_{a}^{b} f(x)g(x) \, dx$$

* **Norm (Length):** $||f||_2 = \sqrt{\langle f, f \rangle} = \left[ \int_{a}^{b} f^2(x) \, dx \right]^{1/2}$
* **Orthogonality:** Two functions are orthogonal if $\langle f, g \rangle = 0$.
* **Orthonormality:** A set $\{\phi_n\}$ is orthonormal if $\langle \phi_n, \phi_m \rangle = 0$ (for $n \neq m$) and $||\phi_n||^2 = 1$.



### 2. Standard Orthogonal Systems
* **Polynomials on $[-1, 1]$:** $\{1, x\}$ are orthogonal because $\int_{-1}^{1} x \, dx = 0$.
* **Trigonometric System on $[-\pi, \pi]$:** The set $\{1, \cos nx, \sin nx\}$ is orthogonal.
    * $\int_{-\pi}^{\pi} \sin nx \sin mx \, dx = 0$ for $n \neq m$.
    * **Norms:** $||1||^2 = 2\pi$, while $||\sin nx||^2 = \pi$ and $||\cos nx||^2 = \pi$.

### 3. Best Approximation (Least Squares)
We wish to approximate $f(x)$ with a sum $S_N(x) = \sum_{n=1}^{N} c_n \phi_n(x)$ by minimizing the **Mean Square Error**:
$$E_N = || f - S_N ||_2^2 = \int_{a}^{b} [f(x) - S_N(x)]^2 \, dx$$

**Theorem:** The error is minimized if $c_n$ are the **Fourier Coefficients**:
$$c_n = \frac{\langle f, \phi_n \rangle}{||\phi_n||^2}$$

**Example 9.1.6:** Approximating $f(x) = x^3 + 1$ on $[-1, 1]$ using $\{1, x\}$:
1.  Calculate $c_1$: $\langle x^3+1, 1 \rangle / \langle 1, 1 \rangle = 1$.
2.  Calculate $c_2$: $\langle x^3+1, x \rangle / \langle x, x \rangle = 3/5$.
3.  **Result:** $S_2(x) = 1 + \frac{3}{5}x$.

### 4. Bessel's Inequality
The error cannot be negative ($E_N \ge 0$), implying the sum of the coefficients converges:
$$\sum_{n=1}^{\infty} c_n^2 ||\phi_n||^2 \le ||f||^2$$
* **Corollary:** Fourier coefficients must decay to zero ($c_n \to 0$) as $n \to \infty$.

---

## 9.2 Completeness and Parseval's Equality

### 1. Convergence in the Mean
A sequence $f_n$ converges to $f$ **in the mean** if the "area" of the squared difference goes to zero:
$$\lim_{n \to \infty} \int_{a}^{b} [f(x) - f_n(x)]^2 \, dx = 0$$
* **Contrast with Pointwise:** A sequence can converge in the mean but fail to converge pointwise (e.g., the "moving bump" counter-example).

### 2. Completeness
An orthogonal system is **Complete** if approximations can get arbitrarily close to *any* integrable function in the mean. This is equivalent to **Parseval's Equality**:
$$\sum_{n=1}^{\infty} c_n^2 ||\phi_n||^2 = ||f||^2$$
*(This is the infinite-dimensional Pythagorean Theorem: sum of squared components = squared length of vector.)*

---

## 9.3 Trigonometric Fourier Series

### 1. Definitions
For a function $f$ on $[-\pi, \pi]$, the Fourier Series is:
$$f(x) \sim \frac{a_0}{2} + \sum_{n=1}^{\infty} (a_n \cos nx + b_n \sin nx)$$

**Formulas:**
* $a_0 = \frac{1}{\pi} \int_{-\pi}^{\pi} f(x) \, dx$
* $a_n = \frac{1}{\pi} \int_{-\pi}^{\pi} f(x) \cos nx \, dx$
* $b_n = \frac{1}{\pi} \int_{-\pi}^{\pi} f(x) \sin nx \, dx$

### 2. Key Calculation Examples
* **Step Function (Example 9.3.3a):**
    * $f(x) = 0$ on $[-\pi, 0)$, $1$ on $[0, \pi)$.
    * Result: $f(x) \sim \frac{1}{2} + \frac{2}{\pi} \sum_{k=0}^{\infty} \frac{\sin(2k+1)x}{2k+1}$ (contains only odd sine terms).
* **Linear Function (Example 9.3.3b):**
    * $f(x) = x$ on $[-\pi, \pi]$.
    * Since $f$ is odd, $a_n = 0$.
    * Result: $x \sim 2 \sum_{n=1}^{\infty} \frac{(-1)^{n+1}}{n} \sin nx$.



### 3. Riemann-Lebesgue Lemma
For any integrable function, the oscillatory integrals decay to zero:
$$\lim_{n \to \infty} \int_{-\pi}^{\pi} f(x) \sin nx \, dx = 0$$
This confirms that high-frequency noise contributes less to the function's structure.

---

## 9.4 Convergence in the Mean (Theoretical Core)

### 1. The Dirichlet Kernel ($D_n$)
The partial sum $S_n$ is an integral convolution of $f$ with $D_n$:
$$D_n(t) = \frac{\sin((n+1/2)t)}{2 \sin(t/2)}$$
* **Issue:** $\int |D_n| \to \infty$. This makes $D_n$ a "bad" kernel; it does not guarantee pointwise convergence for continuous functions easily.

### 2. The Fejér Kernel ($F_n$)
To fix this, we average the partial sums (Cesàro Means, $\sigma_n$). This leads to the Fejér Kernel:
$$F_n(t) = \frac{1}{2(n+1)} \left[ \frac{\sin(\frac{n+1}{2}t)}{\sin(t/2)} \right]^2$$
* **Why it works:** $F_n \ge 0$ and behaves like a true probability distribution (Approximate Identity).



### 3. Fejér's Theorem
**Theorem:** If $f$ is continuous and periodic, the averages $\sigma_n$ converge to $f$ **uniformly**.
* **Consequence:** Since the averages converge, the original partial sums $S_n$ must converge to $f$ **in the mean**.

### 4. Application of Parseval's
Using the series for $f(x)=x$ and Parseval's equality ($\sum c_n^2 = \int f^2$), we can solve the famous Basel problem:
$$\sum_{n=1}^{\infty} \frac{1}{n^2} = \frac{\pi^2}{6}$$

---

## 9.5 Pointwise Convergence

### 1. Dirichlet's Convergence Theorem
When does the series equal $f(x)$ at a specific point?
If $f$ is periodic and at a point $x_0$:
1.  Left/Right limits exist.
2.  Left/Right derivatives exist (or $f$ is Lipschitz).

Then the series converges to the **average of the jump**:
$$\lim_{n \to \infty} S_n(x_0) = \frac{f(x_0+) + f(x_0-)}{2}$$

### 2. Examples
* **Square Wave:** At a jump discontinuity (like $x=0$), the series converges to the midpoint of the jump.
* **Triangular Wave ($|x|$):** Since it is continuous everywhere, the series converges to $|x|$ everywhere.

### 3. Differentiation
We can differentiate a Fourier series term-by-term **only if**:
1.  $f$ is continuous everywhere (including the boundary $f(-\pi)=f(\pi)$).
2.  $f'$ is piecewise continuous.
* *Warning:* If $f$ has jumps (like the square wave), differentiating its series will produce a divergent series.

---

### Next Step
Would you like to try working through a specific calculation example, such as finding the Fourier series for $f(x) = x^2$ to see how it leads to the sum of $1/n^4$?