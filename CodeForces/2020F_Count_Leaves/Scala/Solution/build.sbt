// Project version
version := "0.00.007"

// Version of Scala used by the project
scalaVersion := "3.4.2" //"2.12.19"

// Scalac options
scalacOptions ++= Seq(
  "-unchecked",
  "-deprecation",
  "-encoding",
  "utf8",
  "-feature"
)

// JVM options for running the application
//javaOptions ++= Seq(
//  "-Xmx2G",
//  "-XX:+UseG1GC"
//)
// this doesn't work as intended how
// 		however this is how it is
// sbt -J-Xmx2G -J-XX:+UseG1GC
// sbt -J-Xmx4G -J-XX:+UseG1GC "~runMain MinSubArraySum"
// sbt -J-Xmx4G -J-XX:+UseG1GC -J-XX:+UseParallelGC console
// sbt -J-Xmx4G -J-XX:+UseG1GC -J-XX:+UseParallelGC -J-XX:+UseStringDeduplication -J-XX:+UseCompressedOops -J-XX:MaxPermSize=512M -J-Xss8M -J-XX:+UnlockExperimentalVMOptions
// description
// Increase heap size: -J-Xmx2G (or higher) to allocate more memory to the JVM.
// Enable G1GC: -J-XX:+UseG1GC for better garbage collection performance.
// Enable parallel GC: -J-XX:+UseParallelGC for improved garbage collection performance.
// Increase stack size: -J-Xss4M (or higher) to allow for deeper recursion.
// Enable JVM ergonomics: -J-XX:+UseStringDeduplication to reduce memory usage.
// Enable JVM ergonomics: -J-XX:+UseCompressedOops to reduce memory usage.
// Increase permgen size: -J-XX:MaxPermSize=512M (or higher) for more metadata storage.

