object myCPScaled {
    def main(args:Array[String])
    {
        val num1 = args(0).toInt
        val num2 = args(1).toInt
        val num3 = args(2).toInt

        val lista = List(1, 2, 3)
        val listb = List(4, 5, 6)
        val listc = List(7, 8, 9)

        val cartesian = lista.map( (x: Int) => (listb.map ( (y:Int) => (listc.map( (z:Int) => (x * num1,y * num2,z * num3))))))

        cartesian.foreach(x => (x.foreach(y => (y.foreach {println}))))
    

    }
}