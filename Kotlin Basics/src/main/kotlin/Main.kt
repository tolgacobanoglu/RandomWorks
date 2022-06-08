import java.util.*
import kotlin.collections.HashSet

fun main()
{
    hello()

    //---------------------------------------------Variables
    var x = 5
    x = 20

    val y = 50
    // y = 20

    val name = "Android"
    println(name)

    val job : String = "Software Engineering"
    var age : Int = 8

    val pi = 3.14

    var isBest = false
    isBest = true

    println(isBest)

    //---------------------------------------------Collections

    //                                              Array

    val languageArray = arrayOf("Kotlin","Java","C++")

    println(languageArray.size.toString()+ "\n" + languageArray.contentToString())
    languageArray.sort()
    println(languageArray.contentToString())


    val numbersArray = doubleArrayOf(3.0 , 2.2)
    numbersArray.sort()
    println(numbersArray.contentToString())


    val genericArray = arrayOf("pi",3.14)
    println(genericArray.contentToString())


    //                                              ArrayList

    val languageArrayList = ArrayList<String>()
    languageArrayList.add("Java")
    languageArrayList.add("Kotlin")
    languageArrayList.add("C++")
    println(languageArrayList)

    //                                              LinkedList

    val planetLinkedList = LinkedList<String>()
    planetLinkedList.add("Earth")
    planetLinkedList.add("Mars")
    println(planetLinkedList)

    planetLinkedList.forEach{println(it)}


    //                                              Set
    val numberSet = HashSet<String>()
    numberSet.add("C")
    numberSet.add("C++")
    numberSet.add("C++")
    println(numberSet)

    //                                              Map (Key-Value)
    val foodCaloriesMap = HashMap<String,Int>()
    foodCaloriesMap["Hamburger"] = 1000
    foodCaloriesMap.put("Mocha" , 500)
    println(foodCaloriesMap)


    val mochaCalories = foodCaloriesMap.get("Mocha")
    println("Mocha calories : $mochaCalories")


    //---------------------------------------------WHEN

    val day = "friday"

    when(day) {
        "friday" -> println("friday")
        "monday" -> println("monday")
        "sunday" -> println("sunday")

        else -> println("default")
    }

    //---------------------------------------------LOOP

    //for

    for (i in 0..2)
    {
        println(i)
    }


    paramMethods("HELLO !!!")
    println(returnMethods(3,5))

    var employee = Employee("tolga",22)
    var person = Person("tolga",22)


    //---------------------------------------------NULLABLE
    
    //  in kotlin the variables are default null safety

    var nickname : String? = null //change it nullable

    //using !! , it means nullable object must be not null it will be %100 not null

    //  1- null safety
    if (nickname != null)
    {
        println("not null!!")
    }
    else
    {
        println("it is null")
    }

    // 2- safe call --------not sure is null or not, it will be work
    println(nickname?.toBoolean())


    //3- elvis method

}

fun hello() {
    println("Hello World from Kotlin *_*")
}

fun paramMethods(message : String){
    println(message)
}

fun returnMethods(x:Int,y:Int) : Int
{
    return x*y
}