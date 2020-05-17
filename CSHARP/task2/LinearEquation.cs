using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace task2
{
    public class LinearEquation
    {
        private List<double> coeff = new List<double>();

        public int Size => coeff.Count; //кол-во элементов

        public LinearEquation(string _coeff) //конструктор создания из строки
        {
            char[] sym = new char[] { ' ', '\t', '\n', '\r', ',' };
            string[] arr = _coeff.Split(sym, StringSplitOptions.RemoveEmptyEntries);//разбиваем строку на подстроки на основе символов в массиве
                                                                                    //исключаем пустые элементы из возвращаемое массива
            for (int i = 0; i < arr.Length; ++i)
            {
                arr[i] = arr[i].Replace('.', ',');//заменяем . на ,
                coeff.Add(double.Parse(arr[i]));
            }
        }

        public LinearEquation(double[] _coeff) //массив
        {
            coeff = _coeff.ToList();
        }

        public LinearEquation(List<double> _coeff)//список
        {
            coeff = _coeff.ToList();
        }

        public LinearEquation(IEnumerable<double> _coeff)
        {
            coeff = _coeff.ToList();
        } //обьект IEnumerable <double> будет содержать об\единение элементов двух последовательностей

        public LinearEquation(int n)//n переменных
        {
            if (n <= 0)
                throw new ArgumentException();
            for (int i = 0; i <= n; ++i)
                coeff.Add(0);
        }

        public void RandomIn() //инициализация случайными числами
        {
            Random Rand = new Random();
            for (int i = 0; i < Size; ++i)
                coeff[i] = Rand.Next(0, 100);

        }

        public void SameIn(double x) // инициализация одинаковыми значениями
        {
            for (int i = 0; i < Size; ++i)
                coeff[i] = x;
        }

        public double this[int index] //обращение к переменным
        {
            get
            { //тело аксессора для чтения
                if (index < 0 || index >= Size)
                    throw new IndexOutOfRangeException();
                return coeff[index];
            }
            set
            { //тело аксессора для записи
                if (index < 0 || index >= Size)
                    throw new IndexOutOfRangeException();
                coeff[index] = value;
            }
        }

        public static LinearEquation operator +(LinearEquation a, LinearEquation b)//сложение
        {
            var res = a.coeff.Zip(b.coeff, (first, second) => first + second);
            return new LinearEquation(res);

        }

        public static LinearEquation operator -(LinearEquation a, LinearEquation b)//вычитание
        {
            var res = a.coeff.Zip(b.coeff, (first, second) => first - second);
            return new LinearEquation(res);
        }

        public static LinearEquation operator *(LinearEquation a, double r)//умножение на вещ. число справа
        {
            List<double> res = new List<double>();
            for (int i = 0; i < a.Size; ++i)
                res.Add(a[i] * r);
            return new LinearEquation(res);
        }
        public static LinearEquation operator *(double r, LinearEquation a)//умножение на вещ. число слева
        {
            return a * r;
        }

        public static LinearEquation operator -(LinearEquation a)//умножение на -1
        {
            List<double> res = new List<double>();
            for (int i = 0; i < a.Size; ++i)
                res.Add(-a[i]);
            return new LinearEquation(res);
        }

        public static bool operator ==(LinearEquation a, LinearEquation b) //==
        {
            return a.Equals(b);
        }
        public static bool operator !=(LinearEquation a, LinearEquation b)//!=
        {
            if (a.Equals(b)) return false;
            else return true;
        }

        public static bool operator false(LinearEquation a)//противоречивое уравнение
        {
            if (a) return false;
            else return true;
        }
        public static bool operator true(LinearEquation a)//разрешимое уравнение
        {
            for (int i = 0; i < a.Size - 1; ++i)
                if (a[i] != 0) return true;
            if (a[a.Size - 1] == 0) return true;
            else return false;


        }

        public override string ToString()//вывод уравнения 
        {
            string res = "";
            int i;
            for (i = 0; i < Size - 2; i++)
                res += (coeff[i + 1] >= 0) ? (coeff[i].ToString() + 'x' + (i + 1).ToString() + '+') :
                    (coeff[i].ToString() + 'x' + (i + 1).ToString());
            res += coeff[i].ToString() + 'x' + (i + 1).ToString();
            res += '=' + coeff[Size - 1].ToString();
            return res;


        }

        public static implicit operator double[](LinearEquation a)//неявное преобразование к массиву
        {
            return a.coeff.ToArray();
        }

        public bool IsNull() //проверка эл. на равенство с 0
        {
            for (int i = 0; i < Size; ++i)
                if (this[i] != 0) return false;
            return true;
        }


        public void CopyTo(LinearEquation b)//копирование
        {
            b.coeff = coeff.ToList();
        }
        public override bool Equals(object obj)//сравнение
        {
            LinearEquation b = (LinearEquation)obj;
            for (int i = 0; i < Size; ++i)
                if (Math.Abs(this[i] - b[i]) > 1e-9) return false;
            //если разница между элементами < 1 x 10^(-9) то считаем, что равны
            return true;
        }


    }
}