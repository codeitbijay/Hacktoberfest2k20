-- phpMyAdmin SQL Dump
-- version 5.0.2
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Sep 08, 2020 at 08:06 PM
-- Server version: 10.4.14-MariaDB
-- PHP Version: 7.4.9

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `acourse`
--

-- --------------------------------------------------------

--
-- Table structure for table `admin`
--

CREATE TABLE `admin` (
  `id` int(11) NOT NULL,
  `username` varchar(255) NOT NULL,
  `password` varchar(255) NOT NULL,
  `creationDate` timestamp NOT NULL DEFAULT current_timestamp(),
  `updationDate` varchar(255) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `admin`
--

INSERT INTO `admin` (`id`, `username`, `password`, `creationDate`, `updationDate`) VALUES
(1, 'admin', 'f925916e2754e5e03f75dd58a5733251', '2017-01-24 16:21:18', '06-09-2020 11:18:31 PM');

-- --------------------------------------------------------

--
-- Table structure for table `courseenrolls`
--

CREATE TABLE `courseenrolls` (
  `id` int(11) NOT NULL,
  `staffRegno` varchar(255) DEFAULT NULL,
  `pincode` varchar(255) DEFAULT NULL,
  `session` int(11) DEFAULT NULL,
  `department` int(11) DEFAULT NULL,
  `level` int(11) DEFAULT NULL,
  `semester` int(11) DEFAULT NULL,
  `course` int(11) DEFAULT NULL,
  `enrollDate` timestamp NULL DEFAULT current_timestamp(),
  `marks` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `courseenrolls`
--

INSERT INTO `courseenrolls` (`id`, `staffRegno`, `pincode`, `session`, `department`, `level`, `semester`, `course`, `enrollDate`, `marks`) VALUES
(4, '10806121', '715948', 4, 7, 6, 5, 2, '2018-05-21 10:19:41', 90),
(5, '12345', '131863', 4, 7, 6, 6, 1, '2018-08-25 05:52:34', 0),
(6, '447392', '748550', 4, 8, 5, 7, 5, '2020-08-07 11:45:09', 0),
(7, '070101', '185748', 5, 8, 5, 7, 5, '2020-08-10 11:59:44', 85),
(8, '070101', '185748', 5, 8, 5, 7, 6, '2020-08-10 14:00:43', 0),
(9, '070101', '185748', 5, 8, 5, 7, 0, '2020-09-07 05:47:54', 0),
(13, '070101', '185748', 2, 13, 6, 8, 0, '2020-09-07 06:12:28', 0),
(14, '070101', '185748', 2, 8, 7, 8, 0, '2020-09-07 06:14:26', 0),
(16, '070101', '185748', 2, 11, 6, 7, 3, '2020-09-07 06:23:37', 0),
(17, '070101', '185748', 1, 13, 6, 8, 3, '2020-09-07 10:20:35', 0);

-- --------------------------------------------------------

--
-- Table structure for table `courses`
--

CREATE TABLE `courses` (
  `courseId` int(20) NOT NULL,
  `courseName` varchar(255) NOT NULL,
  `courseCode` varchar(255) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `courses`
--

INSERT INTO `courses` (`courseId`, `courseName`, `courseCode`) VALUES
(1, 'ENGLISH', '001'),
(2, 'CHINESE', '001'),
(3, 'MANDARIN', '001'),
(4, 'SPANISH', '001');

-- --------------------------------------------------------

--
-- Table structure for table `department`
--

CREATE TABLE `department` (
  `id` int(11) NOT NULL,
  `department` varchar(255) DEFAULT NULL,
  `creationDate` timestamp NULL DEFAULT current_timestamp()
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `department`
--

INSERT INTO `department` (`id`, `department`, `creationDate`) VALUES
(8, 'ENGLISH DEPARTMENT', '2020-08-07 11:37:01'),
(9, 'CHINESE DEPARTMENT', '2020-08-07 11:37:13'),
(10, 'SPANISH DEPARTMENT', '2020-08-07 11:37:24'),
(11, 'GERMAN DEPARTMENT', '2020-08-07 11:37:38'),
(12, 'FRENCH DEPARTMENT', '2020-08-07 11:37:54'),
(13, 'ITALIAN DEPARTMENT', '2020-08-07 11:38:38');

-- --------------------------------------------------------

--
-- Table structure for table `details`
--

CREATE TABLE `details` (
  `Id` int(11) NOT NULL,
  `studentName` varchar(255) NOT NULL,
  `creationDate` timestamp NOT NULL DEFAULT current_timestamp() ON UPDATE current_timestamp(),
  `updationDate` varchar(255) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Table structure for table `level`
--

CREATE TABLE `level` (
  `id` int(11) NOT NULL,
  `level` varchar(255) DEFAULT NULL,
  `creationDate` timestamp NULL DEFAULT current_timestamp()
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `level`
--

INSERT INTO `level` (`id`, `level`, `creationDate`) VALUES
(5, 'Level 1', '2017-02-09 19:04:04'),
(6, 'Level 2', '2017-02-09 19:04:12'),
(7, 'Level 3', '2017-02-09 19:04:17');

-- --------------------------------------------------------

--
-- Table structure for table `marks`
--

CREATE TABLE `marks` (
  `id` int(11) NOT NULL,
  `courseCode` varchar(255) DEFAULT NULL,
  `courseName` varchar(255) DEFAULT NULL,
  `noofSeats` int(11) DEFAULT NULL,
  `creationDate` timestamp NULL DEFAULT current_timestamp(),
  `updationDate` varchar(255) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `marks`
--

INSERT INTO `marks` (`id`, `courseCode`, `courseName`, `noofSeats`, `creationDate`, `updationDate`) VALUES
(13, 'mandarin 001', 'shivam ', 3, '2020-08-13 23:34:25', NULL),
(14, 'ENGLISH 001', 'Shivam', 89, '2020-08-14 00:02:05', NULL),
(16, 'mandarin 001', 'tom', 1237, '2020-08-14 06:13:53', '22-08-2020 02:39:15 AM'),
(17, 'ENGLISH 001', 'DAVID', 44, '2020-08-14 14:24:25', '22-08-2020 02:40:18 AM');

-- --------------------------------------------------------

--
-- Table structure for table `semester`
--

CREATE TABLE `semester` (
  `id` int(11) NOT NULL,
  `semester` varchar(255) DEFAULT NULL,
  `creationDate` timestamp NULL DEFAULT current_timestamp(),
  `updationDate` varchar(255) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `semester`
--

INSERT INTO `semester` (`id`, `semester`, `creationDate`, `updationDate`) VALUES
(7, '1st', '2020-08-07 11:41:37', NULL),
(8, '2nd', '2020-08-07 11:41:57', NULL),
(11, '3rd', '2020-08-14 00:08:30', NULL);

-- --------------------------------------------------------

--
-- Table structure for table `session`
--

CREATE TABLE `session` (
  `id` int(11) NOT NULL,
  `session` varchar(255) DEFAULT NULL,
  `creationDate` timestamp NULL DEFAULT current_timestamp()
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `session`
--

INSERT INTO `session` (`id`, `session`, `creationDate`) VALUES
(5, '2019-2020', '2020-08-07 11:46:37'),
(6, '2020-2021', '2020-08-07 11:47:05');

-- --------------------------------------------------------

--
-- Table structure for table `staff`
--

CREATE TABLE `staff` (
  `StaffRegno` varchar(255) NOT NULL,
  `staffPhoto` varchar(255) DEFAULT NULL,
  `password` varchar(255) DEFAULT NULL,
  `staffName` varchar(255) DEFAULT NULL,
  `pincode` varchar(255) DEFAULT NULL,
  `session` varchar(255) DEFAULT NULL,
  `department` varchar(255) DEFAULT NULL,
  `semester` varchar(255) DEFAULT NULL,
  `creationdate` timestamp NULL DEFAULT current_timestamp(),
  `updationDate` varchar(255) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `staff`
--

INSERT INTO `staff` (`StaffRegno`, `staffPhoto`, `password`, `staffName`, `pincode`, `session`, `department`, `semester`, `creationdate`, `updationDate`) VALUES
('070101', 'Capture.PNG', '81dc9bdb52d04dc20036dbd8313ed055', 'Rahul', '185748', NULL, NULL, NULL, '2020-08-07 11:40:56', '07-09-2020 03:56:34 PM'),
('12345678', '', 'f925916e2754e5e03f75dd58a5733251', 'shivam1', '980465', NULL, NULL, NULL, '2020-08-13 23:31:37', '08-09-2020 11:31:29 PM'),
('447392', NULL, 'f925916e2754e5e03f75dd58a5733251', 'United kingdom', '748550', NULL, NULL, NULL, '2020-08-07 11:39:59', NULL);

-- --------------------------------------------------------

--
-- Table structure for table `student`
--

CREATE TABLE `student` (
  `id` int(11) NOT NULL,
  `courseCode` varchar(255) DEFAULT NULL,
  `courseName` varchar(255) DEFAULT NULL,
  `sessionName` varchar(255) DEFAULT NULL,
  `semesterName` varchar(100) NOT NULL,
  `noofSeats` int(11) DEFAULT NULL,
  `creationDate` timestamp NULL DEFAULT current_timestamp(),
  `updationDate` varchar(255) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `student`
--

INSERT INTO `student` (`id`, `courseCode`, `courseName`, `sessionName`, `semesterName`, `noofSeats`, `creationDate`, `updationDate`) VALUES
(11, 'ENGLISH 001', 'Shivam', '2019-2020', '2nd', 12, '2020-08-13 21:53:03', '07-09-2020 03:46:39 PM'),
(13, 'ENGLISH 001', 'shivam123', '2017-2018', '7th', 26, '2020-08-13 23:42:29', '06-09-2020 02:24:26 AM'),
(15, 'ENGLISH 001', 'Rahul', '2020-2021', '6th', 30, '2020-08-14 00:17:12', '06-09-2020 04:47:43 PM'),
(25, 'ENGLISH 001', 'Rizwan', '2017-2018', '1st', 56, '2020-09-03 19:04:30', NULL),
(26, 'MANDARIN 001', 'Kashir', '2017-2018', '4th', 64, '2020-09-03 19:14:28', NULL),
(31, 'ENGLISH 001', 'Rizwan', '2016-2017', '4th', NULL, '2020-09-05 19:51:06', NULL),
(36, 'ENGLISH 001', 'Ishan', '2020-2021', '2nd', NULL, '2020-09-06 17:17:47', NULL);

-- --------------------------------------------------------

--
-- Table structure for table `userlog`
--

CREATE TABLE `userlog` (
  `id` int(11) NOT NULL,
  `studentRegno` varchar(255) DEFAULT NULL,
  `userip` binary(16) DEFAULT NULL,
  `loginTime` timestamp NULL DEFAULT current_timestamp(),
  `logout` varchar(255) DEFAULT NULL,
  `status` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `userlog`
--

INSERT INTO `userlog` (`id`, `studentRegno`, `userip`, `loginTime`, `logout`, `status`) VALUES
(22, '070101', 0x3a3a3100000000000000000000000000, '2020-08-10 09:40:21', NULL, 1),
(23, '070101', 0x3a3a3100000000000000000000000000, '2020-08-10 11:21:26', '10-08-2020 04:52:21 PM', 1),
(24, '070101', 0x3a3a3100000000000000000000000000, '2020-08-10 11:59:07', NULL, 1),
(25, '070101', 0x3a3a3100000000000000000000000000, '2020-08-10 13:59:55', NULL, 1),
(26, '070101', 0x3a3a3100000000000000000000000000, '2020-08-10 15:24:32', '10-08-2020 08:55:02 PM', 1),
(27, '070101', 0x3a3a3100000000000000000000000000, '2020-08-10 17:16:05', '10-08-2020 10:46:16 PM', 1),
(28, '070101', 0x3a3a3100000000000000000000000000, '2020-08-13 20:08:38', '14-08-2020 01:46:31 AM', 1),
(29, '070101', 0x3a3a3100000000000000000000000000, '2020-08-13 20:41:59', '14-08-2020 02:52:49 AM', 1),
(30, '070101', 0x3a3a3100000000000000000000000000, '2020-08-13 21:23:02', NULL, 1),
(31, '070101', 0x3a3a3100000000000000000000000000, '2020-08-13 21:23:19', NULL, 1),
(32, '070101', 0x3a3a3100000000000000000000000000, '2020-08-13 21:24:20', NULL, 1),
(33, '070101', 0x3a3a3100000000000000000000000000, '2020-08-13 21:39:36', NULL, 1),
(34, '070101', 0x3a3a3100000000000000000000000000, '2020-08-13 21:40:53', NULL, 1),
(35, '070101', 0x3a3a3100000000000000000000000000, '2020-08-13 21:41:40', NULL, 1),
(36, '070101', 0x3a3a3100000000000000000000000000, '2020-08-13 21:42:10', NULL, 1),
(37, '070101', 0x3a3a3100000000000000000000000000, '2020-08-13 21:42:37', NULL, 1),
(38, '070101', 0x3a3a3100000000000000000000000000, '2020-08-13 21:47:56', NULL, 1),
(39, '070101', 0x3a3a3100000000000000000000000000, '2020-08-13 21:48:37', '14-08-2020 03:45:49 AM', 1),
(40, '070101', 0x3a3a3100000000000000000000000000, '2020-08-13 23:28:40', '14-08-2020 04:59:22 AM', 1),
(41, '12345678', 0x3a3a3100000000000000000000000000, '2020-08-13 23:32:08', NULL, 1),
(42, '12345678', 0x3a3a3100000000000000000000000000, '2020-08-13 23:37:19', '14-08-2020 05:37:01 AM', 1),
(43, '12345678', 0x3a3a3100000000000000000000000000, '2020-08-14 00:07:08', '14-08-2020 05:37:10 AM', 1),
(44, '12345678', 0x3a3a3100000000000000000000000000, '2020-08-14 00:17:55', NULL, 1),
(45, '12345678', 0x3a3a3100000000000000000000000000, '2020-08-14 00:19:30', '14-08-2020 05:52:21 AM', 1),
(46, '12345678', 0x3a3a3100000000000000000000000000, '2020-08-14 00:30:06', '14-08-2020 06:00:15 AM', 1),
(47, '12345678', 0x3a3a3100000000000000000000000000, '2020-08-14 00:39:19', '14-08-2020 06:09:40 AM', 1),
(48, '12345678', 0x3a3a3100000000000000000000000000, '2020-08-14 00:49:20', '14-08-2020 06:21:39 AM', 1),
(49, '12345678', 0x3a3a3100000000000000000000000000, '2020-08-14 00:57:44', '08-09-2020 11:31:52 PM', 1),
(50, '070101', 0x3a3a3100000000000000000000000000, '2020-08-14 05:05:28', '08-09-2020 11:12:47 PM', 1);

--
-- Indexes for dumped tables
--

--
-- Indexes for table `admin`
--
ALTER TABLE `admin`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `courseenrolls`
--
ALTER TABLE `courseenrolls`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `courses`
--
ALTER TABLE `courses`
  ADD PRIMARY KEY (`courseId`);

--
-- Indexes for table `department`
--
ALTER TABLE `department`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `details`
--
ALTER TABLE `details`
  ADD PRIMARY KEY (`Id`);

--
-- Indexes for table `level`
--
ALTER TABLE `level`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `marks`
--
ALTER TABLE `marks`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `semester`
--
ALTER TABLE `semester`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `session`
--
ALTER TABLE `session`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `staff`
--
ALTER TABLE `staff`
  ADD PRIMARY KEY (`StaffRegno`);

--
-- Indexes for table `student`
--
ALTER TABLE `student`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `userlog`
--
ALTER TABLE `userlog`
  ADD PRIMARY KEY (`id`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `admin`
--
ALTER TABLE `admin`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=2;

--
-- AUTO_INCREMENT for table `courseenrolls`
--
ALTER TABLE `courseenrolls`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=18;

--
-- AUTO_INCREMENT for table `courses`
--
ALTER TABLE `courses`
  MODIFY `courseId` int(20) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=7;

--
-- AUTO_INCREMENT for table `department`
--
ALTER TABLE `department`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=15;

--
-- AUTO_INCREMENT for table `details`
--
ALTER TABLE `details`
  MODIFY `Id` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT for table `level`
--
ALTER TABLE `level`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=8;

--
-- AUTO_INCREMENT for table `marks`
--
ALTER TABLE `marks`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=19;

--
-- AUTO_INCREMENT for table `semester`
--
ALTER TABLE `semester`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=13;

--
-- AUTO_INCREMENT for table `session`
--
ALTER TABLE `session`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=13;

--
-- AUTO_INCREMENT for table `student`
--
ALTER TABLE `student`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=37;

--
-- AUTO_INCREMENT for table `userlog`
--
ALTER TABLE `userlog`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=51;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
