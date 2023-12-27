# Метод конечных разностей
## Описание алгоритма
Дана система следующего вида: 

$$\begin{cases}
    \begin{array}{ccc}
      y'' + \sqrt{x}y' + x^{2}y + x = 0 \\    
      y(0) = 2 \\
      y(1) = 2 \\
    \end{array}
\end{cases}$$

Выписываем разностную схему:  
    $$y'' \sim \frac{y(x+h)-2y(x)+y(x-h)}{h^2}$$ 
    $$y' \sim \frac{y(x+h)-y(x)}{h}$$  
  
$$\begin{cases}
  \begin{array}{ccc}
     \frac{y_{n+1} - 2y_{n} + y_{n-1} + \sqrt{x_n} \cdot h \cdot (y_{n+1}-y_{n})}{h^2} = - x_{n} - x_{n}^2y_{n} = 0 \\
     y_{0} = 2 \\
     y_{N} = 2 \\
  \end{array}
\end{cases}$$  

$$\begin{cases}
  \begin{array}{ccc}
     \frac{ (1 + h\sqrt{x_n}) \cdot y_{n+1}^{k+1} - (2 + h\sqrt{x_n}) \cdot y_{n}^{k+1} + y_{n-1}^{k-1} }{h^2} = - x_{n} - x_{n}^{2}y_{n}^{k} = 0 \\
     y_{0}^{k} = 2  \quad \forall k\\
     y_{N}^{k} = 2  \quad \forall k\\
  \end{array}
\end{cases}$$

На первом шаге получаем следующее матричное уравнение:  

$$\begin{equation}
    \begin{pmatrix}
      1 & 0 & 0 & \ldots & 0 & 0 & 0\\
      \frac{(1 + h\sqrt{1 \cdot h})}{h^2} & -\frac{(2 + h\sqrt{1 \cdot h})}{h^2} & \frac{1}{h^2} & \ldots & 0 & 0 & 0\\
      \vdots & \vdots & \vdots & \vdots & \vdots & \vdots & \vdots\\
      \vdots & \vdots & \vdots & \vdots & \vdots & \vdots & \vdots\\
      \vdots & \vdots & \vdots & \vdots & \vdots & \vdots & \vdots\\
      0 & 0 & 0 &\ldots & \frac{(1 + h\sqrt{((N-1) \cdot h)})}{h^2} & -\frac{(2 + h\sqrt{((N-1) \cdot h)})}{h^2} & \frac{1}{h^2}\\ 
      0 & 0 & 0 &\ldots & 0 & 0 & 1
    \end{pmatrix}
    \times
    \begin{pmatrix}
      y_0^1 \\ 
      y_1^1 \\ 
      \vdots \\ 
      \vdots \\ 
      \vdots \\ 
      y_{N-1}^1 \\ 
      y_N^1
    \end{pmatrix}
    =
    \begin{pmatrix}
      2 \\
      -(1 \cdot h) - (1 \cdot h)^{2}(1 \cdot h) \\
      \vdots \\ 
      \vdots \\ 
      \vdots \\
      -((N-1) \cdot h) - ((N-1) \cdot h)^{2}((N-1) \cdot h) \\
      2
    \end{pmatrix}
\end{equation}$$

Обозначим матрицу 

$$\begin{equation}
A = 
    \begin{pmatrix}
      1 & 0 & 0 & \ldots & 0 & 0 & 0\\
      \frac{(1 + h\sqrt{1 \cdot h})}{h^2} & -\frac{(2 + h\sqrt{1 \cdot h})}{h^2} & \frac{1}{h^2} & \ldots & 0 & 0 & 0\\
      \vdots & \vdots & \vdots & \vdots & \vdots & \vdots & \vdots\\
      \vdots & \vdots & \vdots & \vdots & \vdots & \vdots & \vdots\\
      \vdots & \vdots & \vdots & \vdots & \vdots & \vdots & \vdots\\
      0 & 0 & 0 &\ldots & \frac{(1 + h\sqrt{((N-1) \cdot h)})}{h^2} & -\frac{(2 + h\sqrt{((N-1) \cdot h)})}{h^2} & \frac{1}{h^2}\\ 
      0 & 0 & 0 &\ldots & 0 & 0 & 1
    \end{pmatrix}
\end{equation}$$

Находим вектор

$$\begin{equation}
    \begin{pmatrix}
      y_0^1 \\ 
      y_1^1 \\ 
      \vdots \\ 
      \vdots \\ 
      \vdots \\ 
      y_{N-1}^1 \\ 
      y_N^1
    \end{pmatrix}
    = A^{-1} \times
    \begin{pmatrix}
      2 \\
      -(1 \cdot h) - (1 \cdot h)^{2}(1 \cdot h) \\
      \vdots \\ 
      \vdots \\ 
      \vdots \\
      -((N-1) \cdot h) - ((N-1) \cdot h)^{2}((N-1) \cdot h) \\
      2
    \end{pmatrix}
\end{equation}$$

Далее этот вектор подставляем в матричное уравнение выше и получаем

$$\begin{equation}
    \begin{pmatrix}
      1 & 0 & 0 & \ldots & 0 & 0 & 0\\
      \frac{(1 + h\sqrt{1 \cdot h})}{h^2} & -\frac{(2 + h\sqrt{1 \cdot h})}{h^2} & \frac{1}{h^2} & \ldots & 0 & 0 & 0\\
      \vdots & \vdots & \vdots & \vdots & \vdots & \vdots & \vdots\\
      \vdots & \vdots & \vdots & \vdots & \vdots & \vdots & \vdots\\
      \vdots & \vdots & \vdots & \vdots & \vdots & \vdots & \vdots\\
      0 & 0 & 0 &\ldots & \frac{(1 + h\sqrt{((N-1) \cdot h)})}{h^2} & -\frac{(2 + h\sqrt{((N-1) \cdot h)})}{h^2} & \frac{1}{h^2}\\ 
      0 & 0 & 0 &\ldots & 0 & 0 & 1
    \end{pmatrix}
    \times
    \begin{pmatrix}
      y_0^2 \\ 
      y_1^2 \\ 
      \vdots \\ 
      \vdots \\ 
      \vdots \\ 
      y_{N-1}^2 \\ 
      y_N^2
    \end{pmatrix}
    =
    \begin{pmatrix}
      2 \\
      -(1 \cdot h) - (1 \cdot h)^{2}y_1^1 \\
      \vdots \\ 
      \vdots \\ 
      \vdots \\
      -((N-1) \cdot h) - ((N-1) \cdot h)^{2}y_{N-1}^1 \\
      2
    \end{pmatrix}
\end{equation}$$

Далее находим вектор $y_n^2$ и продолжаем процесс до тех пор, пока 

$$\begin{equation}
dist(y^k, y^{k+1}) = \sum\limits_{i=0}^n h(y_i^{k+1} - y_i^k)^2 	< 10^{-6}
\end{equation}$$

## Описание работы программы
1.     matrixA.cpp  
   Создаем матрицу $A$. В первом цикле заполняем ее нулями. Во втором цикле заполняем ее соответсвующими значениями.
   Обнуляем первую и последнюю строки матрицы, кроме первого и последнего элементов. Их полагаем равными 1. Далее выводим матрицу на экран и возвращаем ее.

2.     invmatrixA.cpp  
   Находим обратную матрицу $A^{-1}$, выводим ее на экран и возвращаем ее.

3.     vector.cpp
    Создаем вектор

$$\begin{equation}
    \begin{pmatrix}
       2 \\
       -(1 \cdot h) - (1 \cdot h)^{2}(1 \cdot h) \\
       \vdots \\ 
       \vdots \\ 
       \vdots \\
       -((N-1) \cdot h) - ((N-1) \cdot h)^{2}((N-1) \cdot h) \\
       2
    \end{pmatrix}
  \end{equation}$$

и записываем его в $vec[i]$. Выводим его на экран и возвращаем его.

4.     vecy.cpp
   Создаем вектор $y[i]$ и записываем в него значения, получаемые по формуле

$$\begin{equation}
    \begin{pmatrix}
      y_0^1 \\ 
      y_1^1 \\ 
      \vdots \\ 
      \vdots \\ 
      \vdots \\ 
      y_{N-1}^1 \\ 
      y_N^1
    \end{pmatrix}
    = A^{-1} \times
    \begin{pmatrix}
      2 \\
      -(1 \cdot h) - (1 \cdot h)^{2}(1 \cdot h) \\
      \vdots \\ 
      \vdots \\ 
      \vdots \\
      -((N-1) \cdot h) - ((N-1) \cdot h)^{2}((N-1) \cdot h) \\
      2
    \end{pmatrix}
\end{equation}$$

Выводим его на экран и возвращаем его.

5.     vector1.cpp
   Создаем вектор

$$\begin{equation}
    \begin{pmatrix}
      2 \\
      -(1 \cdot h) - (1 \cdot h)^{2}y_1^1 \\
      \vdots \\ 
      \vdots \\ 
      \vdots \\
      -((N-1) \cdot h) - ((N-1) \cdot h)^{2}y_{N-1}^1 \\
      2
    \end{pmatrix}
  \end{equation}$$

и записываем его в $vec1[i]$. Выводим его на экран и возвращаем его.

6.     vec1y.cpp
   Создаем вектор $y1[i]$ и записываем в него значения, получаемые по формуле

$$\begin{equation}
    \begin{pmatrix}
      y_0^2 \\ 
      y_1^2 \\ 
      \vdots \\ 
      \vdots \\ 
      \vdots \\ 
      y_{N-1}^2 \\ 
      y_N^2
    \end{pmatrix}
    = A^{-1} \times
    \begin{pmatrix}
      2 \\
      -(1 \cdot h) - (1 \cdot h)^{2}y_1^1 \\
      \vdots \\ 
      \vdots \\ 
      \vdots \\
      -((N-1) \cdot h) - ((N-1) \cdot h)^{2}y_{N-1}^1 \\
      2
    \end{pmatrix}
\end{equation}$$

Выводим его на экран и возвращаем его.

(5 и 6 аналогичны 3 и 4 соответственно, но при следующей итерации)

7.     dist.cpp  
   Считаем сумму $$\sum\limits_{i=0}^n h(y1[i] - y[i])^2$$

8.     int main()
   Задаем значения $n = 11$ и шага $h = 0.1$.  


Делаем первый шаг итерации:  
   Создаем матрицу matrix и передаем ей матрицу, возвращаемую функцией matrix_A(n, h).  
   Создаем матрицу inv_matrix и передаем ей матрицу, возвращаемую функцией inv_matrix_A(n, matrix).  
   Создаем вектор $vec$ и передаем ему вектор, возвращаемый функцией vector_(n, h).  
   Создаем вектор $y$ и передаем ему вектор, возвращаемый функцией vec_y(n, inv_matrix, vec).  
   Таким образом мы находим вектор 
   
$$\begin{equation}
  \begin{pmatrix}
      y_0^1 \\ 
      y_1^1 \\ 
      \vdots \\ 
      \vdots \\ 
      \vdots \\ 
      y_{N-1}^1 \\ 
      y_N^1
  \end{pmatrix}
\end{equation}$$

Далее делаем следующий шаг итерации:  
Создаем вектор $vec1$ и передаем ему вектор, возвращаемый функцией vector1_(n, h, y).  
Создаем вектор $y1$ и передаем ему вектор, возвращаемый функцией vec1_y(n, inv_matrix, vec1).  
Таким образом мы находим вектор

$$\begin{equation}
  \begin{pmatrix}
      y_0^2 \\ 
      y_1^2 \\ 
      \vdots \\ 
      \vdots \\ 
      \vdots \\ 
      y_{N-1}^2 \\ 
      y_N^2
  \end{pmatrix}
\end{equation}$$

(этот шаг итерации нужен для дальнейшего вызова функции dist (n, h, y, y1))  

Далее вводим переменную $d$ и присваиваем ей значение, возвращаемое функцией dist (n, h, y, y1). Выводим значение $d$ на экран для проверки.  
Далее в цикле while мы продолжаем наш итеративный процесс пока не отработает условие остановки. Затем вновь для проверки выводим значение $d$ на экран.  

Далее запускаем тест. В тесте создаем вектор $testVec$ и записываем в него уже посчитанные в точках значения. Затем в тесте сравниваем элементы векторов $testVec$ и $res$, в который мы передаем полученные с помощью нашего метода значения. Если $|res[i] - testVec[i]| < 0.02$, то тест считается пройденным.
