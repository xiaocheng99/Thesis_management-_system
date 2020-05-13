/*
SQLyog Ultimate v12.08 (64 bit)
MySQL - 5.5.28 : Database - lcc
*********************************************************************
*/

/*!40101 SET NAMES utf8 */;

/*!40101 SET SQL_MODE=''*/;

/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;
CREATE DATABASE /*!32312 IF NOT EXISTS*/`lcc` /*!40100 DEFAULT CHARACTER SET utf8 */;

USE `lcc`;

/*Table structure for table `bisheziliao` */

DROP TABLE IF EXISTS `bisheziliao`;

CREATE TABLE `bisheziliao` (
  `bishename` varchar(100) DEFAULT NULL,
  `bishezuozhe` varchar(50) DEFAULT NULL,
  `bishetime` datetime DEFAULT NULL,
  `bishezishu` int(20) DEFAULT NULL,
  `bishewenxian` varchar(255) DEFAULT NULL,
  `bishepinfen` varchar(20) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `bisheziliao` */

insert  into `bisheziliao`(`bishename`,`bishezuozhe`,`bishetime`,`bishezishu`,`bishewenxian`,`bishepinfen`) values ('测试','测试','2020-05-11 12:02:10',200,'测试','良');

/*Table structure for table `student` */

DROP TABLE IF EXISTS `student`;

CREATE TABLE `student` (
  `stuid` int(11) NOT NULL AUTO_INCREMENT,
  `stuname` varchar(50) DEFAULT NULL,
  `stunumber` int(20) DEFAULT NULL,
  `stuage` int(5) DEFAULT NULL,
  `stusex` varchar(20) DEFAULT NULL,
  `stuzhuanye` varchar(50) DEFAULT NULL,
  `stubanji` varchar(30) DEFAULT NULL,
  `stuteacher` varchar(30) DEFAULT NULL,
  `stuphone` int(20) DEFAULT NULL,
  `stupassword` varchar(80) DEFAULT NULL,
  `stubishename` varchar(100) DEFAULT NULL,
  `stubishetime` varchar(30) DEFAULT NULL,
  `stubishezishu` int(20) DEFAULT NULL,
  `stubishewenxian` varchar(255) DEFAULT NULL,
  `stubishepinfen` varchar(20) DEFAULT NULL,
  PRIMARY KEY (`stuid`)
) ENGINE=InnoDB AUTO_INCREMENT=8 DEFAULT CHARSET=utf8;

/*Data for the table `student` */

insert  into `student`(`stuid`,`stuname`,`stunumber`,`stuage`,`stusex`,`stuzhuanye`,`stubanji`,`stuteacher`,`stuphone`,`stupassword`,`stubishename`,`stubishetime`,`stubishezishu`,`stubishewenxian`,`stubishepinfen`) values (1,'1',2,3,'4','5','6','7',8,'123456','9','10',11,'12','1'),(2,'万人',123456,1111111118,'2','2','2','2',2,'2','','2',22,'2','2'),(3,'霆锋对他',3,0,'3','3','3','3',33,'123456','','33',3,'3','3'),(4,'的反弹的',5465465,4,'9','8','98','98',99,'8','放的地方','98',4,'5','5'),(7,'8',8,8,'8','8','','',8,'8','','',0,'','');

/*Table structure for table `teacher` */

DROP TABLE IF EXISTS `teacher`;

CREATE TABLE `teacher` (
  `teaid` int(11) DEFAULT NULL,
  `teaname` varchar(30) DEFAULT NULL,
  `teanumber` int(20) DEFAULT NULL,
  `teaage` int(5) DEFAULT NULL,
  `teasex` varchar(20) DEFAULT NULL,
  `teazhuanye` varchar(50) DEFAULT NULL,
  `teabanji` varchar(50) DEFAULT NULL,
  `teaphone` int(20) DEFAULT NULL,
  `teapassword` varchar(50) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `teacher` */

insert  into `teacher`(`teaid`,`teaname`,`teanumber`,`teaage`,`teasex`,`teazhuanye`,`teabanji`,`teaphone`,`teapassword`) values (1,'1',1,0,'女','1','1',45728956,'123456'),(3,'第三方',123456,NULL,'2','62','5',56,'123456'),(45,'电饭锅',555,56,'女','宿舍','6575',132456,'555');

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;
