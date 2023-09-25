SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";

CREATE TABLE `sensortable` (
  `Temp` varchar(10) NOT NULL,
  `Hum` varchar(10) NOT NULL,
  `Pre` varchar(10) NOT NULL,
  `Date` varchar(10) NOT NULL,
  `Time` varchar(10) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
