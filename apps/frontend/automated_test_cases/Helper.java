import org.openqa.selenium.By;
import org.openqa.selenium.chrome.ChromeDriver;
import org.openqa.selenium.chrome.ChromeOptions;
import org.openqa.selenium.Dimension;
import org.openqa.selenium.remote.DesiredCapabilities;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.WebElement;

import java.util.Date;
import java.io.IOException;
import java.nio.file.*;
import java.text.DateFormat;
import java.text.SimpleDateFormat;


public class Helper
{
    public static WebDriver
    getChromeWebDriver()
    {
        ChromeOptions options = new ChromeOptions();
        options.addArguments("--incognito");
        // options.addArguments("--headless");

        DesiredCapabilities capabilities = DesiredCapabilities.chrome();
        capabilities.setCapability(ChromeOptions.CAPABILITY, options);
        capabilities.setCapability("applicationCacheEnabled", "false");

        System.setProperty("webdriver.chrome.driver", "./chromedriver");

        WebDriver driver = new ChromeDriver(capabilities);

        int browser_width = 1200;
        int browser_height = 600;

        driver.manage().window().setSize(new Dimension(browser_width, browser_height));

        return driver;
    }
    
    
    public static void
    sleepMilliseconds(int milliseconds)
    {
        try
        {
            Thread.sleep(milliseconds);
        }
        catch (InterruptedException interrupted_exception)
        {
            System.out.println(" ");
            System.out.println("ERROR: Thread.sleep(...) throws an exception: " + interrupted_exception.getMessage());
            System.out.println(" ");
        }
    }
    
    
    public static void
    appendTextToLogFile(String text)
    {
        try
        {
            // DateFormat dateFormat = new SimpleDateFormat("HH:mm:ss");

            // String line = dateFormat.format(new Date());
            // line += " ";
            String line = text;
            line += System.getProperty("line.separator");

            Files.write(Paths.get("automated_test_cases.log"), line.getBytes(), StandardOpenOption.APPEND);
        }
        catch (IOException ioException)
        {
            System.out.println("[ERROR] Exception IO Logging: " + ioException.getMessage());
        }
    }


    public static WebElement
    getWebElementByXpath(WebDriver driver, String xpathText)
    {
        WebElement element = null;

        try
        {
            element = driver.findElement(By.xpath(xpathText));
        }
        catch (Exception exception)
        {
            return null;
        }

        return element;
    }

    
    public static String
    getBaseUrlForAutomatedTests()
    {
        return "https://maatuu.li/CompiledWebDevelopment/";
    }
}
