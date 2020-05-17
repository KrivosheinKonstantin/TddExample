using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace task2
{
    public class SystemOfLinearEquation
    {
        private List<LinearEquation> sle = new List<LinearEquation>();
        private int n; //кол-во переменных
        private void Swap(LinearEquation a, LinearEquation b)
        {
            LinearEquation k = new LinearEquation(a); //k=a
            b.CopyTo(a); //a=b
            k.CopyTo(b); //b=k
        }
        public SystemOfLinearEquation(int _n)//n переменных
        {
            n = _n;
        }

        public int Size => sle.Count;//возращает кол-во уравнений

        public LinearEquation this[int i] //обращение к уравнению по его номеру в СЛУ
        {
            get
            {//тело аксессора для чтения
                if (i < 0 || i >= Size)
                    throw new IndexOutOfRangeException();
                else return sle[i];
            }
            set
            {//тело аксессора для записи
                if (i < 0 || i >= Size)
                    throw new IndexOutOfRangeException();
                else sle[i] = value;
            }
        }

        public void Add(LinearEquation a) //добавить уравнение в СЛУ
        {
            if (a.Size - 1 == n) //если можно добавить => добавляем в конец
                sle.Add(a);

        }

        public void Delete(int x)//удалить уравнение из СЛУ
        {
            sle.RemoveAt(x);
        }

        public void StepView() //приведение СЛУ к ступенчатому виду
        {
            int m;
            int z;
            double x, y;
            for (int i = 0; i < Size; ++i)
            {
                z = i;
                if (this[i][z] == 0)//если элемент на главной диагонали равен 0
                {
                    while (this[i][z] == 0 && z < n)//
                        z++;//поиск нулевого элемента в уравнении
                    m = 1;
                    while ((i + m) < Size && this[i + m][z] == 0)
                        m++; //поиск нулевого коэф переменной у нижних уравнений
                    if ((i + m) == Size)//имеет ступенчатый вид
                        return;
                    Swap(this[i], this[i + m]);//опускаем ур-е вниз
                }
                //нормализация уравнений
                for (int j = i + 1; j < Size; j++)
                {
                    x = this[i][z];
                    y = this[j][z];
                    this[j] = this[j] * x - this[i] * y;
                    //элементарными преобразованиями приравнием коэф переменных у нижних уравнений к 0
                }
            }
        }
        //?
        public double[] Solve()//решение
        {
            while (this[Size - 1].IsNull()) //удаляем 0 строки
                this.Delete(Size - 1);
            if (this[Size - 1])//если СЛУ не пуста. Иначе Нет решений
            {
                if (Size == n)
                { //переменных столько же сколько уравнений. Иначе Бесконечно много решений
                    double[] solve = new double[n];
                    for (int i = Size - 1; i >= 0; --i)
                    {
                        solve[i] = this[i][n];// = свободному эллементу
                        for (int j = i + 1; j < n; ++j)
                            solve[i] -= this[i][j] * solve[j];//вычитаем уже найденные элементы

                        solve[i] /= this[i][i];//делим свободный элемент на коэф. неизвестной переменной
                    }
                    return solve;
                }
                else throw new ArgumentException("Решений бесконечно много");
            }
            else throw new ArgumentException("Нет решений");
        }

        public override string ToString()//переопределение метода 
        {
            string res = "";
            for (int i = 0; i < Size; ++i)
                res += this[i].ToString() + '\n';
            return res;
        }


    }
}